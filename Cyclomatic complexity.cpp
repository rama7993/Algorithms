#include<bits/stdc++.h>
using namespace std;

int main()
{
    int E,N,P;
    cout<<"Enter No: of Nodes :";
    cin>>N;
    cout<<"Enter No: of Edges :";
    cin>>E;
    cout<<"Cyclomatic Complexity is V(G):"<<E-N+2<<endl;

    cout<<" OR \n Enter Number of predicate nodes (node that contains condition):";
    cin>>P;
    cout<<"Cyclomatic Complexity is V(G):"<<P+1<<endl;
    return 0;
}
