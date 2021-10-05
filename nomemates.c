#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void handleSignal(int signal){
    printf("\nJajajaja no me mataste\n");
}

int main(){
    signal(2,handleSignal);
    while(1){
        printf("Working . . .\n");
        sleep(1);
    }
    return 0;
}