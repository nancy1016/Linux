/*演示一个信号的产生
 *
 */


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
int main()
{
   //kill(getpid(),SIGSEGV);
    //raise(1);
    //abort();
    alarm(3);
    sleep(1);
    int ret=alarm(5);
    printf("ret:%d\n",ret);
    sigqueue(getpid(),SIGKILL,(union sigval)999);
    while(1)
    {    
        printf("-----\n");
        sleep(1);
    }
    return 0;
}
