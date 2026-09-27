#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define ITERATIONS 1000000  // 100万次，让差距更明显

int shared_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 场景1：无锁（有数据竞争）
void* worker_no_lock(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        shared_counter++;  // 有竞争
    }
    return NULL;
}

// 场景2：粗粒度锁（循环外加锁）
void* worker_coarse_lock(void* arg) {
    int id = *(int*)arg;
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < ITERATIONS; i++) {
        shared_counter++;  // 锁保护，但粒度粗
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// 场景3：细粒度锁（循环内加锁）
void* worker_fine_lock(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        shared_counter++;  // 每次加锁解锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 0, id2 = 1;
    clock_t start, end;
    
    // 测试场景1：无锁
    shared_counter = 0;
    start = clock();
    pthread_create(&t1, NULL, worker_no_lock, &id1);
    pthread_create(&t2, NULL, worker_no_lock, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    end = clock();
    printf("无锁: 结果=%d, 时间=%.3f秒\n", 
           shared_counter, (double)(end-start)/CLOCKS_PER_SEC);
    
    // 测试场景3：细粒度锁
    shared_counter = 0;
    start = clock();
    pthread_create(&t1, NULL, worker_fine_lock, &id1);
    pthread_create(&t2, NULL, worker_fine_lock, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    end = clock();
    printf("细粒度锁: 结果=%d, 时间=%.3f秒\n", 
           shared_counter, (double)(end-start)/CLOCKS_PER_SEC);
    
    // 测试场景2：粗粒度锁
    shared_counter = 0;
    start = clock();
    pthread_create(&t1, NULL, worker_coarse_lock, &id1);
    pthread_create(&t2, NULL, worker_coarse_lock, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    end = clock();
    printf("粗粒度锁: 结果=%d, 时间=%.3f秒\n", 
           shared_counter, (double)(end-start)/CLOCKS_PER_SEC);
    
    return 0;
}
