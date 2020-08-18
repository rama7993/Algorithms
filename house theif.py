def max_sum(arr,idx) :
    if(idx >= len(arr) ):
      return 0
    
    s1=arr[idx]+max_sum(arr,idx+2)
    s2=max_sum(arr,idx+1)
    
    return max(s1,s2)
   

print("enter array : ")
arr=list(map(int,input().split()))
r=max_sum(arr,0)
print(r)