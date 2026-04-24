#include <bits/stdc++.h>
using namespace std;
#define int long long
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

const int MX=5000000;
int ep[MX+10];

unordered_map<int, int> mp;
int Sp(int n) {
    if (n<=MX) return ep[n];
    if (mp.find(n)!=mp.end()) return mp[n];
    int ret=n*(n+1)/2%mod;

    for (int i=2, j; i<=n; i=j+1) {
        j=n/(n/i);
        int tst=(j-i+1)*Sp(n/i)%mod;
        ret=(ret-tst)%mod;
    }
    return mp[n]=ret;
}

signed main(){
    fastio;

    for (int i=1; i<=MX; i++) ep[i]=i;
    for (int i=2; i<=MX; i++) if (ep[i]==i) for (int j=i; j<=MX; j+=i) ep[j]=ep[j]*(i-1)/i;
    for (int i=1; i<=MX; i++) ep[i]=(ep[i]+ep[i-1])%mod;

    int n, ans=0; cin >> n;
    for (int i=1, j; i<=n; i=j+1) {
        j=n/(n/i);
        int F=(fib(j+1)-fib(i)+mod)%mod;
        ans+=F*(2*Sp(n/i)-1)%mod;
    }
    cout << ans%mod;

    return 0;
}
