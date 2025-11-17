//create a process using fork() function
#include<stdio.h>
#include<unistd.h>
int main()
{
  printf("hi..\n");
  fork();  //2^0
  printf("hello..\n");
  fork();  //2^1
  printf("vector\n");
  fork();  //2^2
  printf("India\n");
}
