#include "bits/stdc++.h"
using namespace std;

int N, M, S, A[2520202];

int p(int x, int y) {
    if (A[(x+S)%M] && A[(y+S)%M]) {printf("%d %d\n", (x+S)%M, (y+S)%M); return 1;}
    return 0;
}

void Alice() {
    cin >> N; M=2*N+1; S=0;
    fill(A, A+2*N+1, 0);
    for (int i=1, x; i<=N; i++) cin >> x, S=(S+x)%M, A[x]=1;

    if (N%2==0) {for (int i=1; i<=N-1; i++) if (p(M-i, i)) return;}
    else {for (int i=1; i<=N-1; i++) if (p(i, M-i)) return;}
    for (array<int, 2> i : {array<int, 2>{0, 2*N}, {0, 1}, {N, 2}, {N, 2*N-1}, {4, N+1}, {2*N-3, N+1}})
        if (p(i[0], i[1])) return;
}

int rev(int x, int y) {
    int D=(y-x+M)%M;
    if (N%2==0) {
        if (D%2==0 && D!=M-1) {
            int p=(x+y)%M;
            return p%2?(p+M)/2:p/2;
        }
    }
    if (N%2==1) if (D%2==1 && D!=1) {
        int p=(x+y)%M;
        return p%2?(p+M)/2:p/2;
    }
    if (D==2*N) return x;
    if (D==1) return x;
    if (D==N+3) return (x+N+1)%M;
    if (D==N-1) return (y+2)%M;
    if (D==N-3) return (y+N)%M;
    if (D==N+5) return (x+4)%M;
}

void Bob() {
    cin >> N; M=2*N+1;
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", (M*2-rev(a, b)-rev(c, d))%M);
}

signed main(){
    int T, U;
    scanf("%d%d", &T, &U);
    while (T--) {
        if (U!=3) Alice();
        else Bob();
    }

    return 0;
}
