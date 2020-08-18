res=list()

def per(strg,s,t):
    i=0
    if (s==t-1):
      if not strg in res:
        res.append(strg)
     
    else:
     for i in range(s,t):
         x=list(strg)
         x[i],x[s]=x[s],x[i]
         per(''.join(x),s+1,t)
         x[i],x[s]=x[s],x[i]  
 
 
  
if __name__=="__main__" :
   
 string="abc"
 n=len(string)
 per(string,0,n)
 print (res)
   