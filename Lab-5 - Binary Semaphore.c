#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int x,y;
sem_t sem;
void take_input(void *ptr){
    for (;;){
        printf("%s", (char *)ptr);
        scanf("%d %d", &x, &y);
        sem_post(&sem);
        usleep(100 * 1000);
    }
}
void print_output(void *ptr){
    for (;;){
        sem_wait(&sem);
        printf("%s %d\n", (char *)ptr, x + y);
    }
}
int main()
{
    pthread_t t1;
    pthread_t t2;
    char *m1 = "Enter Number Two No\n";
    char *m2 = "sum = ";
    sem_init(&sem, 0, 0);
    pthread_create(&t1, NULL, (void *)take_input, (void *)m1);
    pthread_create(&t2, NULL, (void *)print_output, (void *)m2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Wait For Both Thread Finished\n");
    sem_destroy(&sem);
    return 0;
}