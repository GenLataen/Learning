#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdatomic.h>  // C11 原子操作

#define ITERATIONS 1000000

int shared_counter = 0;
atomic_int atomic_counter = 0;  // 原子变量
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 使用互斥锁
void* worker_with_lock(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        shared_counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// 使用原子操作
void* worker_atomic(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        atomic_fetch_add(&atomic_counter, 1);  // 原子加1
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 0, id2 = 1;
    clock_t start, end;
    
    // 测试：锁
    shared_counter = 0;
    start = clock();
    pthread_create(&t1, NULL, worker_with_lock, &id1);
    pthread_create(&t2, NULL, worker_with_lock, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    end = clock();
    printf("互斥锁: 结果=%d, 时间=%.3f秒\n", 
           shared_counter, (double)(end-start)/CLOCKS_PER_SEC);
    
    // 测试：原子操作
    atomic_counter = 0;
    start = clock();
    pthread_create(&t1, NULL, worker_atomic, &id1);
    pthread_create(&t2, NULL, worker_atomic, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    end = clock();
    printf("原子操作: 结果=%d, 时间=%.3f秒\n", 
           atomic_counter, (double)(end-start)/CLOCKS_PER_SEC);
    
    return 0;
}
