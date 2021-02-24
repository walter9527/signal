#include <common.h>                                  

// 如果只是需要唤醒，可以使用空的捕获函数
void signal_fun(int signo)
{
    printf("get msg\n");
}

int main(int argc, char *argv[])                     
{                                                    
    signal(SIGUSR1, signal_fun);

    printf("hello\n");

    pause();

    printf("world\n");

    while(1);
    
    return 0;                                        
}         
