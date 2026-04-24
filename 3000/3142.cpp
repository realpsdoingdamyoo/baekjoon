#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int N, M=1000004;
int P[1010101], C[1010101], R;

signed main() {
    fastio;

    for (int i=1; i<=M; i++) P[i]=i;
    for (int i=2; i<=M; i++) if (P[i]==i) {
        for (int j=i; j<=M; j+=i) P[j]=min(P[j], i);
    }

    cin >> N;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        while (a>1) {
            R-=C[P[a]]; C[P[a]]^=1; R+=C[P[a]];
            a/=P[a];
        }
        cout << (R?"NE\n":"DA\n");
    }

    return 0;
}
