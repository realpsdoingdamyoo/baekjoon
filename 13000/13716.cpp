#include <bits/stdc++.h>
using namespace std;
#define int __int128_t
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

array<int, 4> mul(array<int, 4> a, array<int, 4> b) {
    return {(a[0]*b[0]+a[1]*b[2])%mod, (a[0]*b[1]+a[1]*b[3])%mod, (a[2]*b[0]+a[3]*b[2])%mod, (a[2]*b[1]+a[3]*b[3])%mod};
}
int fib(int p) {
    array<int, 4> x={1, 1, 1, 0}, r={1, 0, 0, 1};
    while (p) {if (p%2) r=mul(r, x); p>>=1; x=mul(x, x);}
    return r[0];
}

int PW(int n, int k){int r=1; while (k--) r=r*n%mod; return r;}
int NCR(int n, int r){int s=1; for (int i=n; i>r; i--) s=s*i/(n-i+1); return s%mod;}

int vis[50], val[50];
int f(int n, int k) {
    if (vis[k]++) return val[k];
    if (k==0) return val[k]=(fib(n+2)+mod-2)%mod;
    int ret=(fib(n+1)*PW(n, k)+fib(n)*PW(n+1, k)-1)%mod;
    for (int i=k-1; i>=0; i-=2) ret-=2*NCR(k, i)*f(n, i)%mod;
    return val[k]=(ret%mod+mod)%mod;
}

signed main(){
    fastio;

    long long n, k; cin >> n >> k;
    cout << (long long)f(n, k);

    return 0;
}
