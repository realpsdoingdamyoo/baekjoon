n, t = map(int, input().split())
t += 1
a = 1
m = 998244353
l = [int(input()) for i in range(n)]
for i in range(n - 1, -1, -1):
    t = t - l[i] + 1
    a *= t
    a %= m
a *= (t - n) * pow(t, m - 2, m)
a %= m
print(a)
