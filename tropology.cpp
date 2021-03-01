#include<bits/stdc++.h>
using namespace std;
void star(int n);
void ring(int n);
void tree(int n);
void print(int n,vector<int> adjmatrix[]);


int main()
{ int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"\n\n";
    star(n);
	cout<<"\n\n";
	ring(n);
	cout<<"\n\n";
	tree(n);
	return 0;
}

void star(int n)
{
	cout<<"FOR STAR TOPOLOGY :"<<"\n";
    vector<int> adjmatrix[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0)
			{
				if(j==0)
					adjmatrix[i].push_back(0);
				else
					adjmatrix[i].push_back(1);
			}
			else
			{
				if(j==0)
					adjmatrix[i].push_back(1);
				else
					adjmatrix[i].push_back(0);
			}
		}
	}
    print(n,adjmatrix);
}


void ring(int n)
{
	cout<<"FOR RING TOPOLOGY :"<<"\n";
    vector<int> adjmatrix[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0)
			{
				if(j==1 || j==n-1)
					adjmatrix[i].push_back(1);
				else
					adjmatrix[i].push_back(0);
			}
			else
			{
				if(j==i-1 || j==(i+1)%n)
					adjmatrix[i].push_back(1);
				else
					adjmatrix[i].push_back(0);
			}
		}
	}
	print(n,adjmatrix);
}

void tree(int n)
{
	cout<<"\t"<<"\t"<<"FOR TREE TOPOLOGY :"<<"\n";
	vector<int> adjmatrix[n];
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==2*i+1||j==2*i+2)
                adjmatrix[i].push_back(1);
            else
                adjmatrix[i].push_back(0);
        }
    }
    print(n,adjmatrix);
}


void print(int n,vector<int> adjmatrix[])
{
    cout<<"\nAdjacency matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<adjmatrix[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\nAdjacency list:\n";
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<n;j++)N
            if(adjmatrix[i][j])
                cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\nDegree of each node:\n";
    for(int i=0;i<n;i++)
        cout<<accumulate(adjmatrix[i].begin(),adjmatrix[i].end(),0)<<"   ";
    cout<<"\n";
}
