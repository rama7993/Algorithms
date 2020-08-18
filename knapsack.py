def knapsack(arr,idx,wght,capacity):
    if(capacity <=0 or idx >=len(arr) ) :
        return 0
    p1=0
    p2=0
    if(wght[idx]<= capacity):
      p1=arr[idx]+knapsack(arr,idx+1,wght,capacity-wght[idx])
      p2=knapsack(arr,idx+1,wght,capacity)
    
    return max(p1,p2)



arr=list(map(int,input("enter profits array :").split()))
capacity=int(input("capacity:"))
wght=list(map(int,input("enter weights array :").split()))
r=knapsack(arr,0,wght,capacity)
print(r)
