#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 100
int saldo;

void * suma100(void *arg){
    int lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;

    pthread_exit(NULL); //Here each thread notifies that it has ended
}

int main(){
    saldo = 0;

    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL);
    }
    for(int i =0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    
    printf("Saldo final es de %d\n", saldo);
    pthread_exit(NULL); //Here, main() waits for each thread to be ended before returning 0.
}