import sys

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def bitDP(x, n, k, v, dp):
    for i in range(n):
        if x & (1 << i):
            x -= (1 << i)
            kmd = 1
            for j in range(n):
                if x & (1 << j):
                    kmd = kmd * v[j][1] % k
            for p in range(k):
                dp[x + (1 << i)][(p + kmd * v[i][0]) % k] += dp[x][p]
            x += (1 << i)

def main():
    n=int(input())
    
    v = [[0]*2 for _ in range(n)]
    for i in range(n):
        v[i][0]=int(input())
    
    for i in range(0, n):
        power_of_ten = 1
        s = v[i][0]
        while s > 0:
            s //= 10
            power_of_ten *= 10
        v[i][1]=power_of_ten
    
    k = int(input())
    dp = [[0] * 103 for _ in range(1 << 15)]
    dp[0][0] = 1
    for i in range(2 * n):
        v[i // 2][i % 2] %= k
    for i in range(n + 1):
        for j in range(1 << n):
            s = 0
            for m in range(n):
                s += int(bool(j & (1 << m)))
            if s != i:
                continue
            bitDP(j, n, k, v, dp)
    ans=dp[(1 << n) - 1][0]

    fac=1
    for i in range(1, n+1):
        fac=fac*i
    
    print(f"{ans//gcd(ans, fac)}/{fac//gcd(fac, ans)}")

if __name__ == "__main__":
    main()
