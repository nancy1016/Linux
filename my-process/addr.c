/*
 *
 * 父子进程数据独有的demo
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//定义一个全局变量
int g_val=20;

int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        return -1;
    }
    else if(pid==0)
    {
        //子进程
        g_val=100;
        printf("child val:%d---%p\n",g_val,&g_val);
    }
    else
    {
        //父进程
        sleep(1);
        printf("parent val:%d---%p\n",g_val,&g_val);
    }
    return 0;

}
