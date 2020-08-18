def max_len(s1,i1,i2):
    
    if (i1>i2):
        return 0
    if (i1==i2) :
       return 1
    
    c1=0
    if s1[i1]==s1[i2] : 
      c1=2+max_len(s1,i1+1,i2-1)
      
    c2=max_len(s1,i1+1,i2)
    c3=max_len(s1,i1,i2-1)
    return max(c1,c2,c3)

s1=str(input("enter string 1 :"))
r=max_len(s1,0,len(s1)-1)
print("max length  is :" ,r)