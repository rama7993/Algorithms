#include<stdio.h>
#include<math.h>

void Matrixmultiply(int *A, int *B, int *C, int m, int n)
{
    if(m==2)
    {
        *C+=*A*(*B) + *(A+1)*(*(B+n));                              //C[0][0]=A[0][0]*B[0][0] + A[0][1]*B[1][0]
        *(C+1)+=(*A)*(*(B+1))+(*(A+1))*(*(B+n+1));                      //C[0][1]=A[0][0]*B[0][1] + A[0][1]*B[1][1]
        *(C+n)+=(*(A+n))*(*B)+(*(A+n+1))*(*(B+n));                      //C[1][0]=A[1][0]*B[0][0] + A[1][1]*B[1][0]
        *(C+n+1)+=(*(A+n))*(*(B+1)) + (*(A+n+1))*(*(B+n+1));            //C[1][1]=A[1][0]*B[0][1] + A[1][1]*B[1][1]  
    }
    else
    {
        m=m/2;.
        Matrixmultiply(A,B,C,m,n);
        Matrixmultiply(A,B+m,C+m,m,n);
        Matrixmultiply(A+m,B+m*n,C,m,n);
        Matrixmultiply(A+m,B+m*(n+1),C+m,m,n);
        Matrixmultiply(A+m*n,B,C+m*n,m,n);
        Matrixmultiply(A+m*n,B+m,C+m*(n+1),m,n);
        Matrixmultiply(A+m*(n+1),B+m*n,C+m*n,m,n);
        Matrixmultiply(A+m*(n+1),B+m*(n+1),C+m*(n+1),m,n);
    }
}

int main()
{
    int i,j,k,n1,n2,n3,n,m;
    printf("Enter the order of the 1st Matrix (rows and columns):");
    scanf("%d%d%*c",&n1,&n2);
    int A[n1][n2];
    printf("\nEnter the first matrix:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
            scanf("%d",&A[i][j]);
    }

    printf("\nEnter the no. of columns of the 2nd Matrix:");
    scanf("%d",&n3);
    int B[n2][n3];
    printf("\nEnter the second matrix:\n");
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n3;j++)
           scanf("%d",&B[i][j]);
    }

    if(n1>=n2 && n1>=n3)
        n=n1;
    else if(n2>=n1 && n2>=n3)
        n=n2;
    else
        n=n3;
    int o=1;
    while(n>pow(2,o))
        o=o+1;
    m=pow(2,o);
    int a[m][m],b[m][m],C[m][m];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++){
            a[i][j]=0;
            b[i][j]=0;
        }
    }
    for(i=0;i<n1;i++)
        for(j=0;j<n2;j++)
            a[i][j]=A[i][j];
    for(i=0;i<n2;i++)
        for(j=0;j<n3;j++)
            b[i][j]=B[i][j];

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            C[i][j]=0;
    
    Matrixmultiply(*a,*b,*C,m,m);  
    printf("Multiplied matrix:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n3;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
}
