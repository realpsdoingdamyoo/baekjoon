from decimal import Decimal, getcontext
getcontext().prec = 10000 
a, b = map(Decimal, input().split())
result = a ** b
res=f"{result:.10000f}"
while res[-1]=='0':
    res=res[:-1]
print(res)
