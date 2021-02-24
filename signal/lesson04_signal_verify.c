#include <stdio.h>                                   
#include <signal.h>                                  
#include <stdlib.h>                                  
#include <unistd.h>                                  
                                                                                                 
int main(int argc, char *argv[])                     
{                                                    
    printf("SIG_ERR = %d\n", SIG_ERR);               
    printf("SIG_IGN = %d\n", SIG_IGN);               
    printf("SIG_DFL = %d\n", SIG_DFL);               
    return 0;                                        
}         
