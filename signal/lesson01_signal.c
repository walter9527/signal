#include <stdio.h>
#include <signal.h>

// 信号捕获处理函数
/*
void signal_fun1(int signum)
{
    printf("SIGINT signo=%d\n", signum);
}

void signal_fun2(int signum)
{
    printf("SIGQUIT signo=%d\n", signum);
}
*/


// 将两个信号处理函数合并成一个
void signal_fun(int signum)
{
    if (signum == SIGINT) {
        printf("SIGINT signo=%d\n", signum);
    } else if (signum == SIGQUIT) {
        printf("SIGQUIT signo=%d\n", signum);
    }
}

int main(int argc, char *argv[])
{
    signal(SIGINT, SIG_IGN); // 忽略，此时 ctrl + c 不起作用
    signal(SIGINT, SIG_DFL); // 默认，ctrl + c 又会起作用
    signal(SIGINT, signal_fun); // 捕获
    

    signal(SIGQUIT, SIG_IGN);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGQUIT, signal_fun); // 捕获
    while (1);
    return 0;
}
