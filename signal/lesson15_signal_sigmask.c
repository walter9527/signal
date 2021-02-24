#include <common.h>                                  

void signal_fun(int signo)
{
    sigset_t set, oldset; 

    printf("hello\n");

    sigemptyset(&set); // 将 set 变量置为 0
    sigaddset(&set, SIGINT); // 将 SIGINT 对应的位设置为 1
    sigprocmask(SIG_UNBLOCK, &set, &oldset); // 将信号屏蔽字中 SIGINT 对应的位设置为 0

    /*
        由于屏蔽字始终为 0， 因此信号不会被阻挡
        当有新的信号进来时，捕获函数的进程会中断，去响应新的信号
        因此所有的信号进来，都会被相应
     */
    sleep(10);

    printf("world\n");
}

int main(int argc, char *argv[])                     
{
    signal(SIGINT, signal_fun);

    while (1);
    return 0;
}         
