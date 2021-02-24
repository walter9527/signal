#include <common.h>                                  


void signal_fun(int signo)
{
    printf("PID:%d, signo:%d\n", getpid(), signo);
}

int main(int argc, char *argv[])                     
{                                                    
    pid_t ret = fork();

    //signal(SIGINT, SIG_DFL);
    //signal(SIGINT, SIG_IGN);
    signal(SIGINT, signal_fun);

    if (ret > 0) {
    } else if (ret == 0) {
        execve("a.out", argv, environ);
    }


    while (1);
    return 0;                                        
}         
