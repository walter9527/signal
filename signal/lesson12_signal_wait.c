#include <common.h>                                  

void signal_fun(int signo)
{
   printf("signo = %d\n", signo);
}

int main(int argc, char *argv[])                     
{                                                    
    signal(SIGINT, signal_fun);

    //pause();
    //sleep(10);

/*    
 *  pause 只有在遇到信号，并且信号捕获函数成功返回的情况下，才会有返回值  
 *
    int ret = 0;
    do {
        ret = pause();
    }
    while (ret == -1 && errno == EINTR);
*/

    /*
     * sleep 返回剩余休眠时间
     */
    int ret = 10;
    do {
        ret = sleep(ret);
    } while (ret > 0);

    printf("continue\n");

    //while (1);

    return 0;
}         
