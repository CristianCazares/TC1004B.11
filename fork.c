#include <stdio.h>
#include <unistd.h>

int main(){
    int a = 5;
    printf("%d\n\n",a);
    int pid = fork();
    if(pid == 0){
        printf("Soy el proceso hijo(%d).\n", pid);
    }else{
        printf("Soy el proceso padre (%d).\n", pid);
    }
    printf("hello\n");
    printf("%d\n",a);
    return 0;
}