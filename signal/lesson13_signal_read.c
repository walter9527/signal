#include <common.h>                                  

void signal_fun(int signo)
{
   printf("signo = %d\n", signo);
}

int main(int argc, char *argv[])                     
{
    signal(SIGINT, signal_fun);
    char buf[100] = {};

    read(0, buf, sizeof(buf));

    printf("hello\n");
    return 0;
}         
