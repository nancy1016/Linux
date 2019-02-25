/*
 *
 * 进程退出方式的demo
 * 方式一：main中return
 *          效果等同于exit
 * 方式二：void exit(int status);//库函数
 *          退出一个进程。退出时刷新缓冲区+做其他释放操作
 * 方式三:void _exit(int status);//系统调用
 *          直接退出,直接释放所有资源
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main()
{
    printf("-------");
    sleep(3);
   // exit(0);//最终效果：时隔3秒后，打印出来。说明的问题：字符先写入了缓冲区，调用exit后，缓冲区刷新，所以打印出来。
    //printf函数的作用:将数据打印到显示器上。本质:linux下一切皆文件，显示器也是一个文件，所以printf作用就是将一串数据写入到终端文件中
    //printf是先把数据写入到了缓冲区，不是直接写在文件中

    _exit(0);//最终效果：时隔3秒后，什么都不打印。说明的问题：_exit粗暴退出，直接释放资源

    int i=0;
    for(i=0;i<255;i++)
    {
        printf("%s\n",strerror(i));
    }
    //进程的退出数据只能是一个小于256的数据,因为进程退出码只用了一个字节来存储
    return 257;
    while(1)
    {
        printf("--------\n");
        sleep(1);
    }
}
