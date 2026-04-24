#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

const int MX=200000;
int n;
int v[MX+10];
int m[MX+10]={0, 1};
int p[MX+10];

int inv(int x) {
    int r=1, pw=mod-2;
    while (pw) {if (pw&1) r=r*x%mod; x=x*x%mod; pw>>=1;}
    return r;
}

void solve() {
    cin >> n;
    for (int i=1; i<=MX; i++) v[i]=1;
    int c=1;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b; c=c*(b-a+1)%mod;
        for (int j=1; j<=MX; j++) v[j]=v[j]*(b/j-(a-1)/j)%mod;
    }

    int ans=0;
    for (int i=1; i<=MX; i++) {
        int cnt=0;
        for (int j=1; j<=MX/i; j++) cnt+=v[i*j]*m[j]%mod;
        ans+=cnt*i%mod;
    }
    ans=(ans%mod+mod)%mod;
    cout << (mod-ans*inv(c)%mod)%mod << "\n";
}

signed main() {
    fastio;

    for (int i=1; i<=MX; i++) p[i]=i;
    for (int i=2; i<=MX; i++) if (p[i]==i)
        for (int j=i; j<=MX; j+=i) p[j]=min(p[j], i);
    for (int i=2; i<=MX; i++) m[i]=(i/p[i]%p[i])?-m[i/p[i]]:0;


    int T; cin >> T;
    while (T--) solve();

    return 0;
}
