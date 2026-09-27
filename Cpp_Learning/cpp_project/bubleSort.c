#include <stdio.h>

void bubbleSort(int arr[], int n);
//冒泡排序示例
int main()
{
        //示例数组
        int arr[] = {22,34,54,23,26};
        int n = sizeof(arr) / sizeof(arr[0]);

        //打印为排序的数组
		printf("打印未排序的数组：\n");
        for(int i = 0; i < n; i++)
        {
			printf("%d ",arr[i]);
        }
		printf("\n");
		bubbleSort(arr,n);

        //打印排序后的数组
		printf("打印排序后的数组：\n");
        for(int i = 0; i < n; i++)
        {
			printf("%d ",arr[i]);
        }
		printf("\n");
		
		return 0;
}



//降序冒泡排序函数
void bubbleSort(int arr[], int n)
{
		int i, j, temp;
        //外层循环
		for (int i = 0; i < n-1; i++ )
		
		{
			//内层循环
			for(int j = 0; j < n-1-i; j++)
			{
				if(arr[j] < arr[j+1])
				{
					temp = arr[j] ; 
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}

			}

		}
		
}


