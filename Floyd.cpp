#include<bits/stdc++.h>
using namespace std;
#define M 100
#define INF 9999

void floyd(int g[M][M],int n)
{int i,j,k;
for(k=0;k<n;k++)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g[i][j]>g[i][k]+g[k][j])
            {
                g[i][j]=g[i][k]+g[k][j];
            }
        }
    }

}
for(i=0;i<n;i++)
     { printf("\n");
        for(j=0;j<n;j++)
        { printf("%d ",g[i][j]);
        }

      }

}

int main()
{ int g[M][M],i,j,n;
    printf("enter no.of nodes:\n");
    scanf("%d",&n);
    printf("enter\n");
    for(i=0;i<n;i++)
     { for(j=0;j<n;j++)
         { scanf("%d",&g[i][j]);
            if(g[i][j]==0 && i!=j)
            {
                g[i][j]=INF;
            }
         }
     }
     floyd(g,n);
}
