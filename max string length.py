def max_len(s1,s2,i1,i2):
    
    if(i1==len(s1) or i2==len(s2) ):
        return 0
    
    c1=0
    if s1[i1]==s2[i2] : 
      c1=1+max_len(s1,s2,i1+1,i2+1)
      
    c2=max_len(s1,s2,i1+1,i2)
    c3=max_len(s1,s2,i1,i2+1)
    return max(c1,c2,c3)

s1=str(input("enter string 1 :"))
s2=str(input("enter string 2 :"))
r=max_len(s1,s2,0,0)
print("max length  is :" ,r)