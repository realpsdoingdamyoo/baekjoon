import sys

def solve(S):
    N=len(S)

    for i in range(1, N+1):
        T=str(int(S)*i)
        T='0'*(N-len(T))+T
        if S not in T+T:
            print(S, "is not cyclic")
            return
    print(S, "is cyclic")
    return

for line in sys.stdin:
    S = line.strip()
    if S:
        solve(S)
