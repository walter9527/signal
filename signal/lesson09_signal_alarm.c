#include <common.h>                                  

void signal_fun(int signo)
{
    printf("hello");
    //exit(-1);
}

int main(int argc, char *argv[])                     
{                                                    
    signal(SIGALRM, signal_fun);
    unsigned int ret = alarm(5); // 闹钟

    printf("ret = %d\n", ret);

    sleep(6);

    ret = alarm(6); // 返回上一次设置 alarm 所剩余的时间

    printf("ret = %d\n", ret);

    while(1);
    
    return 0;                                        
}         
