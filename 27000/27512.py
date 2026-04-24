a, b=map(int, input().split())
r=a*b
if a*b%2==1:
    r-=1
print(r)
