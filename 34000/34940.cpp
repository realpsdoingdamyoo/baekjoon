#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
int F[1010101]={1}, FF[1010101]={1};
int mpw(int x, int y) {
    int r=1;
    while (y) {
        if (y&1) r=r*x%mod;
        x=x*x%mod; y>>=1;
    } return r;
}
int inv(int x){return mpw(x, mod-2);}

int M, R=1;

int cal(int s, int e, int y, int x, int v) {
    if (s>e || max(s, e)>M) return 1;
    int f=F[e]*inv(F[s-1])%mod, ff=FF[e]*inv(FF[s-1])%mod;
    return mpw(mpw(f, mod-1+x)*mpw(ff, mod-1+y)%mod, v);
}

signed main() {
    fastio;

    for (int i=1; i<=1000005; i++) {
        F[i]=F[i-1]*i%mod;
        FF[i]=FF[i-1]*mpw(i, i)%mod;
    }

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        int a, b, c; cin >> a >> b >> c;
        int d=b-a+1, l=a-1, r=M-b;
        if (l>r) swap(l, r);
        R=R*cal(d, d+l, 1, 1-d, c)%mod;
        R=R*cal(d+l+1, d+r, 0, l+1, c)%mod;
        R=R*cal(d+r+1, M, -1, M+1, c)%mod;
    }
    cout << R;

    return 0;
}
