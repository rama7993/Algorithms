#include<bits/stdc++.h>
using namespace std;
int node(int n,int vis[],int dis[])
{
    int ind=0,d=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0 && dis[i]<d)
        {
            d=dis[i];
            ind=i;
        }
    }
    return ind;
}
int main()
{
    int n,p,k,pc;
    cout<<"Weighted hybrid topology with star and ring topology\n";
    cout<<"Enter the number of nodes for star topology: ";
    cin>>p;
    cout<<"Nodes are named from 1 to "<<p<<"\nEnter the center node or main node in star topology : ";
    cin>>pc;
    cout<<"Enter the number of nodes for ring topology: ";
    cin>>k;
    cout<<"Nodes are named from "<<p+1<<" to "<<p+k<<"in the order\nEnter the node number in ring which is connected to centeral node in star node: ";
    int kc,e;
    cin>>kc;
    n=p+k;
    int adjacentmatrix[n][n];
    memset(adjacentmatrix,0,sizeof(int)*n*n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==pc-1 && j<p)
            {
                if(i!=j)
                {
                    cout<<"Enter the weight of the edge from "<<i+1<<" to "<<j+1<<" : ";
                    int w;
                    cin>>w;
                    adjacentmatrix[i][j]=w;
                    adjacentmatrix[j][i]=w;
                }
            }
            else if(i>=p && j>=p)
            {
                if((i+1==j) || (i==p && j==n-1))
                {
                    cout<<"Enter the weight of the edge from "<<i+1<<" to "<<j+1<<" : ";
                    int w;
                    cin>>w;
                    adjacentmatrix[i][j]=w;
                    adjacentmatrix[j][i]=w;
                }
            }
            else if(i==pc-1 && j==kc-1)
            {
                cout<<"Enter the weight of the edge from "<<i+1<<" to "<<j+1<<" : ";
                    int w;
                    cin>>w;
                    adjacentmatrix[i][j]=w;
                    adjacentmatrix[j][i]=w;
            }
        }

    }

    int q=1;
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adjacentmatrix[i][j]<<" ";
        }
        cout<<endl;
    }*/
    do
    {
        cout<<"Give the source and destination: ";
        int s,d;
        cin>>s>>d;
        //Dijkstra Implementation starts
        int vis[n],dis[n];
        memset( vis, 0,n*sizeof(int) );
        for(int i=0;i<n;i++) dis[i]=INT_MAX;
        dis[s-1]=0;
        int cyc=n;
        while(cyc--)
        {
            int ind=node(n,vis,dis);
          //  cout<<ind<<" ind\n";
            vis[ind]=1;
            for(int i=0;i<n;i++)
            {
                if(adjacentmatrix[ind][i]!=0)
                {
                    if(dis[ind]+adjacentmatrix[ind][i]<dis[i]) dis[i]=dis[ind]+adjacentmatrix[ind][i];
                }
            }
        }
        //for(int i=0;i<n;i++)cout<<dis[i]<<" ";
        //cout<<endl;

        cout<<"The shortest distance between "<<s<<" and "<<d<<" is "<<dis[d-1]<<endl;
        cout<<"Press 0 to exit or 1 to compute again: ";
        cin>>q;
    }
    while(q!=0);

}
