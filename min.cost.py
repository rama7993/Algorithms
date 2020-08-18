def min_cost(arr,col,row):
    
    if ( row ==-1 or col ==-1):
        return -999
    
    if ( col==0 and  row ==0):
       return arr[0][0]
    
    c1=min_cost(arr,col-1,row)
    c2=min_cost(arr,col,row-1)
    c3=min_cost(arr,col-1,row-1)
    return max(c1,c2,c3)+arr[row][col]

row,col=map(int,input().split())
print("enter array:")
arr=[]
for i in range (row):
     mat=[]
     for j in range (col):
        mat.append(int(input()))
     arr.append(mat)
    
print(arr)
r=min_cost(arr,col-1,row-1)
print(r)