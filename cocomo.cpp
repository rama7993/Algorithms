#include<bits/stdc++.h>
using namespace std;

int main()
{
int system;
cout<<"Enter the system type (organic:0,semidetached:1,embedded:2): ";
cin>>system;
float c[3]={2.4,3.0,3.6};
float k[3]={1.05,1.12,1.20};
float exponent[3] = {0.38,0.35,0.32};

int modules,i;
cout<<"\nEnter no. of modules:";
cin>>modules;
cout<<"\n Enter size of each module in KLOC:\n";
float size =0;
for(i=0;i<modules;i++){
cout<<"module "<<i+1<<":";
float y;
cin>>y;
size=size+y;}

cout<<"\n Enter the no of attributes which are not nominal: ";

int attributes;
cin>>attributes;
cout<<"\n Enter value of each attribute:\n";
float EAF=1;

for(i=0;i<attributes;i++){
cout<<"Attribute "<<i+1<<": ";
float y;
cin>>y;
EAF=EAF*y;
}

float effort = EAF*c[system]*pow(size,k[system]);
float time =2.5*pow(effort,exponent[system]);
float staff= effort/time;
cout<<fixed<<setprecision(2);
cout<<"\nEffort = "<<effort<<" Person-Month";
cout<<"\nDevelopment Time = "<<time<<" Months";
cout<<"\nAverage Staff Required = "<<(int)round(staff)<<" Persons";
}
