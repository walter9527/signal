#include <common.h>                                  

void signal_fun(int signo)
{
    printf("hello\n");

    sleep(10);

    printf("world\n");
}

int main(int argc, char *argv[])                     
{
    signal(SIGINT, signal_fun);

    while (1);
    return 0;
}         
