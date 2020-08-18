#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];

int main()
{
    int nodes;
    cout<<"enter nodes:"<<endl;
    cin >> nodes;
    int edges;
     cout<<"enter edges:"<<endl;
    cin >> edges;

    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
     cout<<"enter start node:"<<endl;
    cin >> start;
     for(int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }

  queue<int> q;
  q.push(start);
  while(!q.empty())
  { int u=q.front();
     q.pop();
    if(!visited[u])
        {visited[u]=true;
         cout<<u<<endl;
        }
    vector<int>::iterator ptr;
    for(ptr=adj[u].begin();ptr!=adj[u].end();ptr++)
    	{
    		if(!visited[*ptr])
    			q.push(*ptr);
    	}
  }

   return 0;
}
