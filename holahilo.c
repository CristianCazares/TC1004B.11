#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

void * printHola(void *arg){
    char *c = (char *)arg;
    printf("hola desde un hilo \n");

    pthread_exit(NULL); //Here each thread notifies that it has ended
}

int main(){
    pthread_t threads[NUM_THREADS];
    char *s = "soy un argumento";
    for(int i = 0; i < NUM_THREADS; i++){
        printf("(%d) ",i);
        pthread_create(&threads[i], NULL, printHola, (void *) s);
    }
    
    pthread_exit(NULL); //Here, main() waits for each thread to be ended before returning 0.
}