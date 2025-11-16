#include<stdio.h>
#include<setjmp.h>
typedef int FUN_DECLARE(int,int);
FUN_DECLARE sum,sub,mul,div,mod;
jmp_buf var;
int main()
{
int x,y,z,ret;
char op;
ret = setjmp(var);   //setjmp return 0 when it exectues first time 
if(ret == 1)
printf("Problem in mul function, multiply with 0 value\n");
else if(ret == 2)
printf("Problem in div function, divide by 0 value\n");
 
     printf("Enter the x,y values\n");
     scanf("%d%d",&x,&y);
printf("Enter your option '+','-','*','/','%%'\n");
scanf(" %c",&op);	
 
switch(op)
{
       case '+': z = sum(x,y); break;
       case '-': z = sub(x,y); break;
       case '*': z = mul(x,y); break;
       case '/': z = div(x,y); break;
       case '%': z = mod(x,y); break;
       default : printf("Invalid option\n");
       return 0;
  }
 
  printf("%d %c %d = %d\n",x,op,y,z);	
}
int sum(int x,int y)
{
       return x+y;	
}
 
int sub(int x,int y)
{
       return x-y;	
}
 
int mod(int x,int y)
{
       return x%y;	
}
int mul(int x,int y)     //if the x or y or x and y values are 0 it goes to the ret=setjmp(var).
                          //so, ret=1 this return 1 and  exectues if statement
{
      if((x == 0)||(y == 0))
      longjmp(var,1);
      else
      return x*y;	
}
 
int div(int x,int y)  //if the y value are 0 it goes ret=setjmp(var);, so ret=2 this returns 2
                      //and it executes else if statement
{
       if(y == 0)
       longjmp(var,2);
       else
       return x/y;	
 }
