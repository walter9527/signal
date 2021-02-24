#include <stdio.h>                                   
#include <signal.h>                                  
#include <stdlib.h>                                  
#include <unistd.h>                                  

int main(int argc, char *argv[])                     
{                                                    
    for (int i = 0; i < 64; i++) {
        // 忽略所有的信号，只有 SIGKILL 和 SIGSTOP 不可以被忽略
        signal(i, SIG_IGN);
    }

    while (1);
    return 0;                                        
}         
