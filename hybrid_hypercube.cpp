#include<bits/stdc++.h>
using namespace std;
void hybrid(int p,int k,int pc,int kc);
void hypercube(int d);
int main()
{
	int n,d,p,k,pc;
	cout<<"Hybrid topology with star and ring topology\n";
    cout<<"Enter the number of nodes for star topology: ";
    cin>>p;
    cout<<"Nodes are named from 1 to "<<p<<"\nEnter the center node or main node in star topology : ";
    cin>>pc;
    cout<<"Enter the number of nodes for ring topology: ";
    cin>>k;
    cout<<"Nodes are named from "<<p+1<<" to "<<p+k<<"in the order\nEnter the node number in ring topology which is connected to central node in star topology: ";
    int kc,e;
    cin>>kc;
	hybrid(p,k,pc,kc);
	cout<<"\nEnter the dimension of HYPERCUBE: ";
	cin>>d;
	hypercube(d);
}
void hybrid(int p,int k,int pc,int kc)
{
	int n=p+k;
    int adjacentmatrix[n][n];
    memset(adjacentmatrix,0,sizeof(int)*n*n);
    vector<int> adjacentlist[n];
    int degree[n];
    memset( degree, 0,n*sizeof(int) );
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==pc-1 && j<p)
            {
                if(i!=j)
                {
                    adjacentmatrix[i][j]=1;
                    adjacentmatrix[j][i]=1;
                    adjacentlist[i].push_back(j+1);
                    adjacentlist[j].push_back(i+1);
                    degree[i]++;
                    degree[j]++;
                }
            }
            else if(i>=p && j>=p)
            {
                if((i+1==j) || (i==p && j==n-1))
                {
                    adjacentmatrix[i][j]=1;
                    adjacentmatrix[j][i]=1;
                    adjacentlist[i].push_back(j+1);
                    adjacentlist[j].push_back(i+1);
                    degree[i]++;
                    degree[j]++;
                }
            }
            else if(i==pc-1 && j==kc-1)
            {
                    adjacentmatrix[i][j]=1;
                    adjacentmatrix[j][i]=1;
                    adjacentlist[i].push_back(j+1);
                    adjacentlist[j].push_back(i+1);
                    degree[i]++;
                    degree[j]++;
            }
        }

    }
    cout<<"For Hybrid Topology:\n \nThe Adjacency List: \n";
    for(int i=0;i<n;i++)
    {
        cout<<"  "<<i+1<<" -> ";
        for(int j=0;j<adjacentlist[i].size();j++)
        {
            cout<<adjacentlist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n The Adjacency Matrix: \n";
    for(int i=-2;i<n;i++)
    {
        for(int j=-2;j<n;j++)
        {
            if(i==-2 && j==-2) cout<<"    ";
            else if(i==-2 && j!=-2)
            {
                if(j==-1) cout<<"| ";
                else cout<<j+1<<" ";
            }
            else if(j==-2 && i!=-2)
            {
                if(i==-1) cout<<"  _ ";
                else cout<<"  "<<i+1<<" ";
            }
            else
            {
                if(i==-1) cout<<"_ ";
                else if(j==-1) cout<<"| ";
                else cout<<adjacentmatrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"\n The Degree of the Nodes:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"  Degree for "<<i+1<<" is "<<degree[i]<<endl;
    }
}
void hypercube(int d)
{
	cout<<"For  Hypercube Topology:\n";
	int n=pow(2,d);
	int adjacentmatrix[n][n],i,j,degree[n];
	 memset( degree, 0,n*sizeof(int) );
	vector<int> adjacentlist[n];
	memset(adjacentmatrix,0,sizeof(int)*n*n);
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j=j*2)
		{
			adjacentmatrix[i][i^j]=1;
			adjacentlist[i].push_back((i^j)+1);
			degree[i]++;
		}
	}
	cout<<"\n The Adjacency list:\n";
	for(int i=0;i<n;i++)
    {
        cout<<"  "<<i+1<<" -> ";
        for(int j=0;j<adjacentlist[i].size();j++)
        {
            cout<<adjacentlist[i][j]<<" ";
        }
        cout<<endl;
    }
	cout<<"\n The Adjacency Matrix: \n";
    for(int i=-2;i<n;i++)
    {
        for(int j=-2;j<n;j++)
        {
            if(i==-2 && j==-2) cout<<"    ";
            else if(i==-2 && j!=-2)
            {
                if(j==-1) cout<<"| ";
                else cout<<j+1<<" ";
            }
            else if(j==-2 && i!=-2)
            {
                if(i==-1) cout<<"  _ ";
                else cout<<"  "<<i+1<<" ";
            }
            else
            {
                if(i==-1) cout<<"_ ";
                else if(j==-1) cout<<"| ";
                else cout<<adjacentmatrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"\n The Degree of the Nodes:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"  Degree for "<<i+1<<" is "<<degree[i]<<endl;
    }
}
