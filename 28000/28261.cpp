#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, q, r;
string s, p;

array<int, 2> fac[1010101]={{1, 0}};

int nCr(int N, int R) {
    return fac[N][1]-fac[R][1]-fac[N-R][1]?0:fac[N][0]*fac[R][0]*fac[N-R][0]%3;
}

char NX[200]="WDM";

signed main(){
    fastio;

    NX['W']='D'; NX['D']='M'; NX['M']='W';
    for (int i=1; i<=1010100; i++) {
        int j=i; fac[i]=fac[i-1];
        while (j%3==0) fac[i][1]++, j/=3;
        fac[i][0]=fac[i][0]*j%3;
    }


    cin >> n >> s >> q;
    int X; if (n%2) X=1; else X=-1;
    p.resize(n+1, 'W'); s=" "+s;
    for (int i=1; i<=n; i++) {
        while (p[i]!=s[i]) r=(r+X*nCr(n-1, i-1)+3)%3, p[i]=NX[p[i]];
    }

    cout << NX[r] << "\n";

    for (int i=1; i<=q; i++) {
        int a; char b; cin >> a >> b;
        while (p[a]!=b) r=(r+X*nCr(n-1, a-1)+3)%3, p[a]=NX[p[a]];
        cout << NX[r] << "\n";
    }

    return 0;
}
