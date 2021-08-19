#include<stdio.h>
#define M 10
#define INF 9999

int g[M][M],span[M][M],n;

int prims()
{
    int cost[M][M],dist[M],pred[M],i,j;
    int visited[M],min_path,min,count,from,next;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
          if(g[i][j]==0)
          {
              cost[i][j]=INF;
          }
          else
            cost[i][j]=g[i][j];
            span[i][j]=0;
        }
    }
     for(i=1;i<n;i++)
     {
         visited[i]=0;
         dist[i]=cost[0][i];
         pred[i]=0;
     }
     dist[0]=0;
     visited[0]=1;
  min_path=0;
  count=1;
  while(count<n-1)
  { min=INF;
   for(i=1;i<n;i++)
   {
       if(visited[i]==0 && dist[i]<min)
       {
           min=dist[i];
           next=i;
       }
   }
       from=pred[next];
       span[from][next]=dist[next];
       span[next][from]=dist[next];
       visited[next]=1;
      count++;
  for(i=1;i<n;i++)
  {
      if(visited[i]==0 && cost[i][next]<dist[i])
      {
       dist[i]=cost[i][next];
       pred[i]=next;
      }
      min_path+=cost[from][next];
  }
}
return min_path;
}

int main()
{
    int i,j,cost;
    printf("enter n:\n");
    scanf("%d",&n);
    printf("enter\n");
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             scanf("%d",&g[i][j]);
         }
     }
     cost=prims();
      printf("\n cost is:%d \nspan tree is\n ",cost);
      for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
            printf("%d ",span[i][j]);
         }
         printf("\n");
     }


    return 0;
}
