/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"
#include "usart.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <includes.h>
#include "stm32f1xx_hal.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* 任务优先级 */
#define START_PRIO			3
#define Alarm_PRIO			4
#define Display_PRIO		5
#define TempHum_PRIO		6
#define Light_PRIO			7
#define Log_PRIO				8
	
/* 任务堆栈大小	*/
#define START_STK_SIZE 			128
#define Alarm_STK_SIZE 			128
#define Display_STK_SIZE 		128
#define TempHum_STK_SIZE 		128
#define Light_STK_SIZE			128
#define Log_STK_SIZE				128

/* 任务栈 */	
CPU_STK START_STK[START_STK_SIZE];
CPU_STK ALARM_STK[Alarm_STK_SIZE];
CPU_STK DISPLAY_STK[Display_STK_SIZE];
CPU_STK TEMPHUM_STK[TempHum_STK_SIZE];
CPU_STK LIGHT_STK[Light_STK_SIZE];
CPU_STK LOG_STK[Log_STK_SIZE];



/* 任务控制块 */
OS_TCB StartTCB;
OS_TCB AlarmTCB;
OS_TCB DisplayTCB;
OS_TCB TempHumTCB;
OS_TCB LightTCB;
OS_TCB LogTCB;

OS_SEM       DataReadySem;    // 数据就绪信号量
OS_Q         DataQueue;       // 数据消息队列
OS_FLAG_GRP  AlarmFlagGrp;    // 报警事件标志组

/* 传感器数据结构 */
typedef struct {
    float temperature;
    float humidity;
    uint16_t light;
} SensorData;



/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* 任务函数定义 */
void start_task(void *p_arg);
static  void  AppTaskCreate(void);
static  void  AppObjCreate(void);
static  void  Alarm_Task(void *p_arg);
static  void  Display_Task(void *p_arg);
static  void  TempHum_Task(void *p_arg);
static  void  Light_Task(void *p_arg);
static  void  Log_Task(void *p_arg);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	OS_ERR  err;
	OSInit(&err);
	HAL_Init();
	SystemClock_Config();
	//MX_GPIO_Init(); 这个在BSP的初始化里也会初始化
	MX_USART1_UART_Init();	
	/* 创建任务 */
	OSTaskCreate((OS_TCB     *)&StartTCB,                /* Create the start task                                */
				 (CPU_CHAR   *)"start task",
				 (OS_TASK_PTR ) start_task,
				 (void       *) 0,
				 (OS_PRIO     ) START_PRIO,
				 (CPU_STK    *)&START_STK[0],
				 (CPU_STK_SIZE) START_STK_SIZE/10,
				 (CPU_STK_SIZE) START_STK_SIZE,
				 (OS_MSG_QTY  ) 0,
				 (OS_TICK     ) 0,
				 (void       *) 0,
				 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
				 (OS_ERR     *)&err);
	/* 启动多任务系统，控制权交给uC/OS-III */
	OSStart(&err);            /* Start multitasking (i.e. give control to uC/OS-III). */
               
}


void start_task(void *p_arg)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	p_arg = p_arg;
	
	/* add */
	BSP_Init();                                                   /* Initialize BSP functions */
	//CPU_Init();
	//Mem_Init();                                                 /* Initialize Memory Management Module */

#if OS_CFG_STAT_TASK_EN > 0u
   OSStatTaskCPUUsageInit(&err);  		//统计任务                
#endif
	
#ifdef CPU_CFG_INT_DIS_MEAS_EN			//如果使能了测量中断关闭时间
    CPU_IntDisMeasMaxCurReset();	
#endif

#if	OS_CFG_SCHED_ROUND_ROBIN_EN  		//当使用时间片轮转的时候
	 //使能时间片轮转调度功能,时间片长度为1个系统时钟节拍，既1*5=5ms
	OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif		
	
	OS_CRITICAL_ENTER();	//进入临界区
	/* 创建报警任务 */
	OSTaskCreate((OS_TCB 	* )&AlarmTCB,		
				 (CPU_CHAR	* )"alarm_task", 		
                 (OS_TASK_PTR )	Alarm_Task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Alarm_PRIO,     
                 (CPU_STK   * )&ALARM_STK[0],	
                 (CPU_STK_SIZE)Alarm_STK_SIZE/10,	
                 (CPU_STK_SIZE)Alarm_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);		

	/* 创建显示任务 */
	OSTaskCreate((OS_TCB 	* )&DisplayTCB,		
				 (CPU_CHAR	* )"display_task", 		
                 (OS_TASK_PTR )Display_Task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Display_PRIO,     
                 (CPU_STK   * )&DISPLAY_STK[0],	
                 (CPU_STK_SIZE)Display_STK_SIZE/10,	
                 (CPU_STK_SIZE)Display_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);										 
				 
	/* 创建温湿度采集任务 */
	OSTaskCreate((OS_TCB 	* )&TempHumTCB,		
				 (CPU_CHAR	* )"temphum_task", 		
                 (OS_TASK_PTR )TempHum_Task, 			
                 (void		* )0,					
                 (OS_PRIO	  )TempHum_PRIO,     	
                 (CPU_STK   * )TEMPHUM_STK[0],	
                 (CPU_STK_SIZE)TempHum_STK_SIZE/10,	
                 (CPU_STK_SIZE)TempHum_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
				 
	/* 创建光照任务 */
	OSTaskCreate((OS_TCB 	* )&LightTCB,		
				 (CPU_CHAR	* )"light_task", 		
                 (OS_TASK_PTR )Light_Task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Light_PRIO,     	
                 (CPU_STK   * )&LIGHT_STK[0],	
                 (CPU_STK_SIZE)Light_STK_SIZE/10,	
                 (CPU_STK_SIZE)Light_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
				 
	/* 创建日志任务 */
	OSTaskCreate((OS_TCB 	* )&LogTCB,		
				 (CPU_CHAR	* )"log_task", 		
                 (OS_TASK_PTR )Log_Task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Log_PRIO,     	
                 (CPU_STK   * )&LOG_STK[0],	
                 (CPU_STK_SIZE)Log_STK_SIZE/10,	
                 (CPU_STK_SIZE)Log_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
				 
	OS_TaskSuspend((OS_TCB*)&StartTCB,&err);		//挂起开始任务			 
	OS_CRITICAL_EXIT();	//进入临界区
}
/**
  * 函数功能: 报警任务。
  * 输入参数: p_arg 是在创建该任务时传递的形参
  * 返 回 值: 无
  * 说    明：无
  */
static  void  Alarm_Task (void *p_arg)
{
  OS_ERR err;

	/* 报警标志 */
	OS_FLAGS flags;
	
  (void)p_arg;

  BSP_Init();                                                 /* Initialize BSP functions                             */
  CPU_Init();

  Mem_Init();                                                 /* Initialize Memory Management Module                  */

#if OS_CFG_STAT_TASK_EN > 0u
  OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

  CPU_IntDisMeasMaxCurReset();

  //AppTaskCreate();                                            /* Create Application Tasks                             */

 // AppObjCreate();                                             /* Create Application Objects                           */

  while (DEF_TRUE)
  {

		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
		//OSTimeDlyHMSM(0, 0, 1, 0,OS_OPT_TIME_HMSM_STRICT,&err);
//		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
//		OSTimeDlyHMSM(0, 0, 1, 0,OS_OPT_TIME_HMSM_STRICT,&err);
//	  
//	   // 等待报警事件
//        flags = OSFlagPend(&AlarmFlagGrp, ALARM_TEMP_HIGH, 0,
//                          OS_OPT_PEND_FLAG_SET_ALL + OS_OPT_PEND_BLOCKING,
//                          0, &err);
//        
//        if(flags & ALARM_TEMP_HIGH) {
//            // 触发报警 (用LED模拟)
//            HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
           UART_SendString("ALARM: Temperature too high!\r\n");

//            // 报警持续2秒
//            OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err);
//            HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
	  //        // 短延时确保显示更新平滑
        OSTimeDlyHMSM(0, 0, 0, 100, OS_OPT_TIME_HMSM_STRICT, &err);

 // }
  /* USER CODE END 3 */
}

}


/**
  * 函数功能: 显示任务。
  * 输入参数: p_arg 是在创建该任务时传递的形参
  * 返 回 值: 无
  * 说    明：无
  */
static  void  Display_Task (void *p_arg)
{
	OS_ERR err;

	/* 显示buff */
    SensorData *p_data;
    OS_MSG_SIZE msg_size;
    uint8_t disp_buf[64];
	
		(void)p_arg;

		BSP_Init();                                                 /* Initialize BSP functions                             */
		CPU_Init();

		Mem_Init();                                                 /* Initialize Memory Management Module                  */

		#if OS_CFG_STAT_TASK_EN > 0u
		OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
		#endif

		CPU_IntDisMeasMaxCurReset();

		//AppTaskCreate();                                            /* Create Application Tasks                             */

		// AppObjCreate();                                             /* Create Application Objects                           */

		while (DEF_TRUE)
		{
		
//		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
//		OSTimeDlyHMSM(0, 0, 3, 0,OS_OPT_TIME_HMSM_STRICT,&err);
		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_SET);
		//OSTimeDlyHMSM(0, 0, 3, 0,OS_OPT_TIME_HMSM_STRICT,&err);

//	    // 等待数据就绪信号量
        OSSemPend(&DataReadySem, 0, OS_OPT_PEND_BLOCKING, 0, &err);
//        
//        // 从消息队列获取数据
//        p_data = OSQPend(&DataQueue, 0, OS_OPT_PEND_BLOCKING, &msg_size, 0, &err);
//        
//        // 在串口显示数据
//        sprintf((char*)disp_buf, "Temp: %.1fC  Hum: %.1f%%  Light: %d lux\r\n",
//               p_data->temperature, p_data->humidity, p_data->light);
//        UART_SendString(disp_buf);
//        
//        // 释放内存
//        free(p_data);
//        
//        // 短延时确保显示更新平滑
        OSTimeDlyHMSM(0, 0, 0, 100, OS_OPT_TIME_HMSM_STRICT, &err);
    }
}


/**
  * 函数功能: 温湿度采集任务。
  * 输入参数: p_arg 是在创建该任务时传递的形参
  * 返 回 值: 无
  * 说    明：无
  */
static  void  TempHum_Task(void *p_arg)
{
  OS_ERR      err;

	/* 传感器数据 */
	SensorData *p_data;
  (void)p_arg;

  BSP_Init();                                                 /* Initialize BSP functions                             */
  CPU_Init();

  Mem_Init();                                                 /* Initialize Memory Management Module                  */

#if OS_CFG_STAT_TASK_EN > 0u
  OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

  CPU_IntDisMeasMaxCurReset();

  AppTaskCreate();                                            /* Create Application Tasks                             */

  AppObjCreate();                                             /* Create Application Objects                           */

  while (DEF_TRUE)
  {
		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
		OSTimeDlyHMSM(0, 0, 1, 0,OS_OPT_TIME_HMSM_STRICT,&err);
		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
		OSTimeDlyHMSM(0, 0, 1, 0,OS_OPT_TIME_HMSM_STRICT,&err);
		// 模拟从DHT22读取数据
        p_data = (SensorData*)malloc(sizeof(SensorData));
       // p_data->temperature = 25.0 + (rand() % 100) / 10.0; // 模拟25.0-35.0℃
		

		
        p_data->humidity = 40.0 + (rand() % 300) / 10.0;    // 模拟40.0-70.0%
        
        // 发送到消息队列
        OSQPost(&DataQueue, p_data, sizeof(SensorData*), OS_OPT_POST_FIFO, &err);
        
        // 触发报警检查
        if(p_data->temperature > 30.0) {
            OSFlagPost(&AlarmFlagGrp, ALARM_TEMP_HIGH, OS_OPT_POST_FLAG_SET, &err);
        }
        
        // 释放信号量通知数据就绪
        OSSemPost(&DataReadySem, OS_OPT_POST_1, &err);
        
        // 阻塞延时1秒
        OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_STRICT, &err);
    }
  }
  /* USER CODE END 3 */



/**
  * 函数功能: 光照任务。
  * 输入参数: p_arg 是在创建该任务时传递的形参
  * 返 回 值: 无
  * 说    明：无
  */
static  void  Light_Task(void *p_arg)
{
  OS_ERR      err;
	/* 传感器数据 */
	SensorData *p_data;
  (void)p_arg;

  BSP_Init();                                                 /* Initialize BSP functions                             */
  CPU_Init();

  Mem_Init();                                                 /* Initialize Memory Management Module                  */

#if OS_CFG_STAT_TASK_EN > 0u
  OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

  CPU_IntDisMeasMaxCurReset();

  AppTaskCreate();                                            /* Create Application Tasks                             */

  AppObjCreate();                                             /* Create Application Objects                           */

  while (DEF_TRUE)
  {
		//printf("hello uc/OS! 欢迎来到RTOS多任务环境！\r\n");
		//OSTimeDlyHMSM(0, 0, 2, 0,OS_OPT_TIME_HMSM_STRICT,&err);

	  // 模拟从光敏电阻读取数据
        p_data = (SensorData*)malloc(sizeof(SensorData));
        p_data->light = rand() % 1000; // 模拟0-1000lux
        
        // 发送到消息队列
        OSQPost(&DataQueue, p_data, sizeof(SensorData*), OS_OPT_POST_FIFO, &err);
        
        // 释放信号量通知数据就绪
        OSSemPost(&DataReadySem, OS_OPT_POST_1, &err);
        
        // 阻塞延时1秒
        OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_STRICT, &err);
    }
	  
  }


/**
  * 函数功能: 日志任务。
  * 输入参数: p_arg 是在创建该任务时传递的形参
  * 返 回 值: 无
  * 说    明：无
  */
static  void  Log_Task(void *p_arg)
{
  OS_ERR      err;
	/* 日志数据 */
	SensorData *p_data;
    OS_MSG_SIZE msg_size;
    uint8_t log_buf[128];
    uint32_t timestamp;
	
	
  (void)p_arg;

  BSP_Init();                                                 /* Initialize BSP functions                             */
  CPU_Init();

  Mem_Init();                                                 /* Initialize Memory Management Module                  */

#if OS_CFG_STAT_TASK_EN > 0u
  OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

  CPU_IntDisMeasMaxCurReset();

  AppTaskCreate();                                            /* Create Application Tasks                             */

  AppObjCreate();                                             /* Create Application Objects                           */

  while (DEF_TRUE)
  {
		printf("hello uc/OS! 欢迎来到RTOS多任务环境！\r\n");
		OSTimeDlyHMSM(0, 0, 2, 0,OS_OPT_TIME_HMSM_STRICT,&err);
	// 获取当前时间戳
        timestamp = OSTimeGet(&err);
        
        // 从队列中获取最新数据
        p_data = OSQPend(&DataQueue, 0, OS_OPT_PEND_NON_BLOCKING, &msg_size, 0, &err);
        
        if(p_data != NULL) {
            // 格式化日志条目
            sprintf((char*)log_buf, "[%lu] Temp:%.1f Hum:%.1f Light:%d\r\n",
                   timestamp, p_data->temperature, 
                   p_data->humidity, p_data->light);
            
            // 输出到串口(模拟写入文件)
            UART_SendString(log_buf);
            
            // 释放内存
            free(p_data);
        }
        
        // 每5秒记录一次
        OSTimeDlyHMSM(0, 0, 5, 0, OS_OPT_TIME_HMSM_STRICT, &err);
    }
}





/* USER CODE BEGIN 4 */
/**
  * 函数功能: 创建应用任务
  * 输入参数: p_arg 是在创建该任务时传递的形参
  * 返 回 值: 无
  * 说    明：无
  */
static  void  AppTaskCreate (void)
{
  
}


/**
  * 函数功能: uCOSIII内核对象创建
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
static  void  AppObjCreate (void)
{

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
