//fork() function return value
#include<stdio.h>
#include<unistd.h>
int main()
{
    int  ret = fork();
    if(ret == 0)  //child process
    {
        printf("Exclusively child process\n");
        printf("child pid : %d ppid : %d\n",getpid(),getppid());
    }
    else  //parent process
    {
        printf("Exclusively parent process\n");
        printf("parent pid : %d ppid : %d\n",getpid(),getppid());
    }
}


//note: first the parent process gets exectued and the child process return 0 so ret == 0 so 
//fisrt else (parent process) will exectue and the if (child process) will gets exectued
