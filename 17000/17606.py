def gcd(a, b):
  if a*b==0:
    return a+b
  if a==b:
    return a
  return gcd(a%b, b%a)


l=1
c=2
ar=5
clist=[]
for _ in range(10):
  while True:
    c+=1
    if gcd(c*c+1, l)==1:
      l*=(c*c+1)
      clist.append(c)
      break
for i in range(10):
  ar*=clist[i]**2+1


p=int(input())
print(ar)
dls=[0 for _ in range(10)]
for i in range(p):
  ii=i
  a=3
  b=4
  for j in range(10):
    dls[9-j]=ii%2
    ii//=2
  for j in range(10):
    cj=clist[j]
    if dls[j]==1:
       a, b=a*(cj*cj-1)+b*cj*2, -a*cj*2+b*(cj*cj-1)
    else:
      a*=cj**2+1
      b*=cj**2+1
  print(a, b)
