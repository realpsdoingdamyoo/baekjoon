#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, L, K, P[1010101];

int cnt(int s, int l) {
    int ans=0;
    if (l>L) ans+=P[L]*(l/L), l%=L;
    if (s+l-1>L) return ans+(P[L]-P[s-1])+(P[s+l-1-L]);
    return ans+(P[s+l-1]-P[s-1]);
}

signed main() {
    fastio;

    cin >> N >> L >> K;
    for (int i=1; i<=K; i++) {
        int x; cin >> x;
        P[x]=1;
    }
    for (int i=1; i<=L; i++) P[i]+=P[i-1];

    int S=1, C=1, T=0;
    while (C<=N*L) {
        int cc=C;
        C+=S;
        S+=cnt((cc-1)%L+1, S);
        T++;
    }
    cout << T << "\n";

    return 0;
}
