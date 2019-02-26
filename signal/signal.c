/*修改信号的处理方式：
 * signal
 */


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sigcb(int signo)
{
    printf("recv signo:%d\n",signo);
}
int main()
{
    signal(SIGINT,sigcb);
    while(1)
    {
        printf("------\n");
        sleep(1);
    }

    return 0;
}
