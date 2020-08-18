def get_ways(n):
   
  if(n==1 or n==2 or n==0):
     return 1
  if(n==3):
      return 2

  s1=get_ways(n-1)
  s3=get_ways(n-3)
  s4=get_ways(n-4)
  return (s1+s4+s3)


n=int(input("please enter:"))
r=get_ways(n)
print(r)