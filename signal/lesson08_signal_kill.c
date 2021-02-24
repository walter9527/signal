#include <common.h>                                  


int main(int argc, char *argv[])                     
{                                                    
    //kill(getpid(), SIGUSR1); // 用户定义信号 1
    kill(3560, SIGUSR1);
    raise(SIGKILL); // 已杀死

    /* 
     * raise(SIGKILL) 相当于 kill(getpid(), SIGKILL) 
     */

    while(1);
    
    return 0;                                        
}         
