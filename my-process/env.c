/*
 *
 * 演示环境变量全局特性的一个demo
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//获取环境变量第一种方式:命令行第三个参数
void env1(char*env[])
{
    int i;
    for(i=0;env[i]!=NULL;i++)
    {
        printf("%s\n",env[i]);
    }

}

//第二种方式：全局变量environ
void env2()
{
    //这是一个全局变量,定义在c库中，使用时需要声明
    extern char**environ;
    int i;
    for(i=0;environ[i]!=NULL;i++)
    {
        printf("%s\n",environ[i]);
    }
}

//第三种方式：getenv获取指定环境变量中的内容
void env3()
{
    printf("path:%s",getenv("MYVAL"));
}
int main(int argc,char*argv[],char*env[])
{
    //env1(env);
    //env2();
    env3();
    return 0;
}
