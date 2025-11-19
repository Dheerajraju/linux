//simplex communication
  #include<stdio.h>
  #include<string.h>
  #include<unistd.h>
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
              char b[20];
              read(fd[0],b,sizeof(b));  //fd[0] -> read end
              printf("in child reading the string : %s\n",b);
          }
          else
          {
              char a[20];
              printf("Enter the string in parent: ");
              scanf("%s",a);
              write(fd[1],a,strlen(a)+1);  //fd[1] -> write end
          }
  }

