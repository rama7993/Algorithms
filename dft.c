#include<stdio.h>
#include<math.h>
#define pi 22.0/7
void DFT(int a[],float c[],float d[],int n)
{
    int i,j;
    float real,img,angle;
    for(i=0;i<n;i++)
    {
        real=0;
        img=0;
        for(j=0;j<n;j++)
        {
            angle=(2*pi*i*j)/n;
            real+=(a[j]*cos(angle));
            img+=(-a[j]*sin(angle));
        }
        c[i]=real;
        d[i]=img;
    }

}
int main()
{
    int n,i;
    printf("Enter no of sample points: ");
    scanf("%d",&n);
    int a[n];
    float c[n],d[n];
    printf("Enter the sample points:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter a%d : ",i);
        scanf("%d",&a[i]);
    }
    DFT(a,c,d,n);
    printf("Output:\n");
    for(i=0;i<n;i++)
        printf("A%d (real,img): (%.1f,%.1f)\n",i,c[i],d[i]);

}
