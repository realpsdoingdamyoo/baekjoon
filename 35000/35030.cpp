#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int P[5050505], X=5050005;
int S[101010];

int iss(int x) {
    int p=10;
    while (p<=x) {
        if (P[(x/p)*(x%p)+1]==0) return 0;
        p*=10;
    }
    if (P[x+1]==0) return 0;
    return 1;
}

signed main() {
    fastio;

    for (int i=2; i<=X; i++) P[i]=1;
    for (int i=2; i<=X; i++) if (P[i]) for (int j=i*2; j<=X; j+=i) P[j]=0;

    for (int i=1; i<=100000; i++) S[i]=iss(i)+S[i-1];

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << S[x] << "\n";
    }


    return 0;
}
