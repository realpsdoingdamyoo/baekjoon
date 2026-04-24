import math

def ncr(n, r):
    if n < 0 or r < 0 or r > n:
        return 0
    ans = 1
    for i in range(n, n-r, -1):
        ans = ans * i // (n - i + 1)
    return ans

def dv(n, r, z):
    if r * 2 - 2 > n:
        return 0
    if r == 0:
        return 0
    if r == 1:
        return 1
    n -= r * 2 - z
    return ncr(n + r - 1, r - 1) % 100000

def main():
    n, m = map(int, input().split())
    s = 0
    n -= 1
    m -= 1
    for i in range(1, n + 1):
        s += dv(n, i, 2) * dv(m, i - 1, 0)
        s += dv(n, i, 1) * dv(m, i, 1) * 2
        s += dv(n, i, 0) * dv(m, i + 1, 2)
        s %= 100000
    print(s)

if __name__ == "__main__":
    main()
