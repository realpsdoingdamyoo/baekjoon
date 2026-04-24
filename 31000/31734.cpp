#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q, d, a, b;
int L[202020], R[202020], M=1, C[202020];
array<int, 2> A[202020], B[202020];
int F[202020], pos[202020];

int get(int x) {
    int l=1, r=M;
    while (l<=r) {
        int m=l+r>>1;
        if (B[m][1]>=x) r=m-1;
        else l=m+1;
    }
    return l;
}

void solve1() {
    while (Q--) {
        int x; cin >> x;
        int p=get(x);
        if (p==M+1 || B[p][0]>x) cout << "-1\n";
        else cout << x*a+C[p]*(b-a*d) << "\n";
    }
}

int ask(int x) {
    int p=get(x);
    if (B[p][0]>x) x=B[--p][1];
    return F[p]+(x-B[p][0])/d+((x-B[p][0])%d>=pos[p]);
}

void solve2() {
    F[1]=0; pos[1]=d;
    for (int i=2; i<=M; i++) {
        F[i]=ask(B[i][0]-d)+1;
        int l=B[i][0], r=min(B[i][1], B[i][0]+d-1); pos[i]=d;
        while (l<=r) {
            int m=l+r>>1;
            if (ask(m-d)==F[i]) pos[i]=m-B[i][0], r=m-1;
            else l=m+1;
        }
    }
    while (Q--) {
        int x; cin >> x;
        int p=get(x);
        if (p==M+1 || B[p][0]>x) cout << "-1\n";
        else cout << x*a+(F[p]+(x-B[p][0])/d+((x-B[p][0])%d>=pos[p]))*(b-a*d) << "\n";
    }
}

signed main() {
    fastio;

    cin >> N >> Q >> d >> a >> b;
    for (int i=1; i<=N; i++) cin >> L[i] >> R[i];
    A[1]={0, L[1]-1}; L[N+1]=inf;
    for (int i=1; i<=N; i++) A[i+1]={R[i]+1, L[i+1]-1};
    B[M]=A[1];
    for (int i=1, j=1; i<=N+1; i++) {
        while (j<=M && B[j][1]+d<A[i][0]) j++;
        if (j<=M && B[j][0]+d<=A[i][1])
            B[++M]={max(B[j][0]+d, A[i][0]), A[i][1]}, C[M]=C[j]+1;
    }
    if (d*a<b) solve1();
    else solve2();

    return 0;
}
