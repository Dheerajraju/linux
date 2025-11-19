#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
      int count=0;
      char ch='A';
      int fd[2];
      if(pipe(fd) < 0)
      {
          perror("pipe");
          return 0;
      }
      while(write(fd[1],&ch,1) != -1)
      {
           count++;
           printf("size = %d\n",count);
      }
}

