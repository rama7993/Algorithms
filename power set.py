#include<bits/stdc++.h>
using namespace std;

void power(char st[],int idx,char a)
{  if(idx == st.length())
       cout << a <<endl ;

   power(st,idx+1,a+st[i]);
   power(st,idx+1,a) ;
}


void main()
{

  char st[]={ a,b,c};
  char str="";
 power(st,0,str)

}
