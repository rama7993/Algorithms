#include<bits/stdc++.h>
using namespace std;

void main()
{
    int i,j,k,l;
    //Get Data to be Transmitted
    int K;
    string data;
    cout<<"enter K:";
	cin>>K;
	cout<<"enter K bit data:";
	cin>>data;

    //Get Generator Polynomial
    int m;
    cout<<"enter m of X^m+X+1 such that m<K:";
	cin>>m;
	string key;
	cout<<"enter key(generator):";
	cin>>key;

    cout<<"\n Sender Side:";
    cout<<"\n K bit data: "<<data<<endl;
    cout<<"\n Generator :"<<key<<endl;

    //Append 0's
    cout<<"\n Number of 0's to be appended: "<<m-1;
    cout<<"\n Message after appending 0's :"<<data.append(m-1,'0');// m-1 'ZERO' bits to be append to the data

    //Division

    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";


    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receiver Is Correct";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receiver Contains Error";
    }
    getch();
}
