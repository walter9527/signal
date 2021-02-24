#include <common.h>                                  

int main(int argc, char *argv[])                     
{                                                    
    //abort(); // 已放弃 (核心已转储))
    raise(SIGABRT); // abort 是 raise 的一个特例

    while(1);
    
    return 0;                                        
}         
