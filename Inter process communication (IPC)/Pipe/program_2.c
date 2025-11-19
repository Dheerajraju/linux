//half duplex communication
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
  int fd[2];
  if(pipe(fd)<0)
{
  perror("pipe");
  return 0;
}

printf("fd[0]=%d fd[1]=%d\n",fd[0],fd[1]);

if(fork()==0)
{
char s1[20],s2[20];
while(1)
{
read(fd[0],s1,sizeof(s1));
printf("in child reading the string:%s",s1);
scanf("%s",s2);
write(fd[1],s2,strlen(s2)+1);
sleep(1);
}
}
else
{
char a[20],b[20];
while(1)
{
printf("enter the string:");
scanf("%s",a);
write(fd[1],a,strlen(a)+1);
sleep(1);
read(fd[0],b,sizeof(b));
printf("in parent, reading the string:%s",b);
}
}
}
