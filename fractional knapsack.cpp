#include<bits/stdc++.h>
using namespace std;

struct item
{ int val;
  int weight;
  float density;
};

void input(item items[],int n)
{
 for(int i=0;i<n;i++)
 {
     cout<<"enter value"<<i+1<<":";
     cin>>items[i].val;
     cout<<"enter weight"<<i+1<<":";
     cin>>items[i].weight;
 }

}

void display(item items[],int n)
{ int i;
    cout<<"values:  ";
    for(i=0;i<n;i++)
    {
        cout<<items[i].val<<"\t";
    }
    cout<<endl<<"weight:  ";
    for(i=0;i<n;i++)
    {
        cout<<items[i].weight<<"\t";
    }
    cout<<endl;
}

bool comp(item x,item y)
{
  return (x.density>y.density);
}


float knapsack(item arr[],int n,int cap)
{
   int i,j;
   float tot_val,tot_wght;
   for(i=0;i<n;i++)
    {arr[i].density=arr[i].val/arr[i].weight;
    }
   sort(arr,arr+n,comp);
   cout<<"taken values are:"<<endl;
  for(i=0;i<n;i++)
  {
    if(tot_wght+arr[i].weight<=cap)
    {
        tot_val+=arr[i].val;
        cout<<arr[i].val<<endl;
        tot_wght+=arr[i].weight;
    }
     else
     { int wt=cap-tot_wght;
        tot_val+=(wt*arr[i].density);
        cout<<wt<<"*"<<arr[i].density<<endl;
        tot_wght+=wt;
     }
  }
   return tot_val;
}

int main()
{ int n,cap;
 cout<<"enter n:";
  cin>>n;
  item items[n];
  input(items,n);
  display(items,n);
  cout<<"enter capacity"<<endl;
  cin>>cap;
  float Max=knapsack(items,n,cap);
  printf("\ntotal value:%.2f\n",Max);
}
