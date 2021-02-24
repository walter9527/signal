#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// 将 SIGINT 由异常终止转为正常终止
void signal_fun1(int signum)
{
    printf("SIGINT signo=%d", signum);

    // 这里会做两件事，1.刷新标准IO，2.调用进程终止处理函数
    //exit(-1); // ^ChelloSIGINT signo=2process oversave list to file

    // 这里则直接正常终止，不会刷新 IO 缓存，也不会调用进程终止处理函数
    _exit(-1); // ^C
}

// 进程终止处理函数
void process_exit_deal_fun()
{
    printf("process over");
    printf("save list to file");
}

int main(int argc, char *argv[])
{

    atexit(process_exit_deal_fun);

    signal(SIGINT, signal_fun1);
    
    // printf 是行缓存，如果没有遇到/n，
    // 或者库缓存没有满，或者没有主动调用 fflush，或者关闭文件
    // 则不会刷新缓存
    printf("hello");
    while (1);
    return 0;
}
