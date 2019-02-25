/*
 *
 * 进程等待的demo,避免产生僵尸进程
 */


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>


int main()
{
    int pid=fork();
    if(pid<0)
    {
        perror("fork error");
        exit(-1);
    }
    else if(pid==0)
    {
        sleep(10);
        exit(233);
    }
    int statu;
    while(waitpid(pid,&statu,WNOHANG)==0)
    {
        printf("-------why???\n");
        sleep(1);
    }
    //计算退出码的方式一：
    if(WIFEXITED(statu))
    {
        printf("exit code:%d\n",WEXITSTATUS(statu));
    }
    //计算退出码的方式二：利用位运算;先取出低八位判断程序是否正常退出，如果正常退出，则高8位里退出码;如果异常退出，则不用取退出码
    if((statu&0x7f)==0)
    {
        //正常退出
        printf("exit code:%d\n",(statu>>8)&0xff);
    }
    printf("child exit code:%d\n",statu);
    while(1)
    {
        printf("-------\n");
        sleep(1);                                                                                                                             
    }
    return 0;
}




