#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void signal_fun1(int signum)
{
    printf("SIGINT signo=%d\n", signum);
}


int main(int argc, char *argv[])
{
    sighandler_t ret = NULL;

    /* 返回上次的处理类型 */
    /* 有 SIG_ERR，SIG_IGN，SIG_DFL 三种 */
    ret = signal(SIGINT, SIG_IGN); // 忽略，此时 ctrl + c 不起作用
    ret = signal(SIGINT, SIG_DFL); // 默认，ctrl + c 又会起作用
    ret = signal(SIGINT, signal_fun1); // 捕获
    // ret = signal(SIGINT, SIG_DFL);

    // 处理错误，返回 SIG_ERR
    if (ret == SIG_ERR) {
        perror("signal fail");
    } else if (ret == SIG_IGN){
        printf("ignore!\n");
    } else if (ret == SIG_DFL) {
        printf("default!\n");
    } else {
        printf("capture: %p\n", ret); // 信号处理函数的地址
    }

    while (1);
    return 0;
}
