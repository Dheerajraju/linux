//simplex communication
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
  int fd[2];
if(pipe(fd)>0)
{
perror("pipe");
return 0;
}

printf("fd[0]=%d, fd[1]=%d\n",fd[0],fd[1]);
if(fork()==0)
{
char b[20];
read(fd[0]=%d,b,sizeof(b));  //fd[0] -> used for read end
printf("in child reading the string=%s\n");
}
else 
{
char a[20];
printf("enter the string in parent\n");
scnaf("%s",a);
write(fd[1],a,strlen(a)+1);  //fd[1] -> used for write end
}
}
