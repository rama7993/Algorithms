#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void swap (char *x, char *y)
{
    char temp;

    temp=*x;
     *x=*y;
     *y=temp;

}

void permt(char *x ,int s,int t)
{
     if(s==t-1)
     {
        printf(" %s  " , x);
         return;

     }


  else
  {  int i;
       for( i=s;i<t;i++)

           swap(&x[s],&x[i]);
           permt(x,s+1,t);
           swap(&x[s],&x[i]);
  }

}

void main()
{
   char x[]= "abc" ;
   int  n=strlen(x);

     permt(x,0,n);
}
