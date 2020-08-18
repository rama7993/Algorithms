n=int(input("enter n:"))
a=[[0]*n for i in range (n)]
a[0][(n-1) //2]=1
i=0
j=(n-1)/2

for val in range(2,n**2 +1):
    
    if(i>=1):
        k=i-1
    else :
        k=n-1
    if(j>=1):
        l=j-1
    else :
        l=n-1
    if (a[int(k)][int(l)] >= 1):
        i=(i+1)%n
    else :
        i=k
        j=l
    a[int(i)][int(j)]=val
          
for i in a:
    print(i)