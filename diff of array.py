def min_dif(arr):
    n=len(arr)
    diff=abs(arr[0]-arr[1])
    for i in range (n-1):
       if ( abs(arr[i]- arr[i+1]) < diff ):
         diff= abs(arr[i]- arr[i+1])

    return diff

m=int(input())
arr=sorted(list(map(int,input().split())))
k= min_dif(arr)
print(k)