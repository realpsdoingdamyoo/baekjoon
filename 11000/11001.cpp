#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=9e18;

int N, D, T[101010], V[101010], ans;

void dnc(int s, int e, int l, int r) {
    if (s>e) return;
    int m=s+e>>1, op=max(m-D, l);
    for (int i=max(m-D, l); i<=min(m, r); i++) if ((m-op)*T[m]+V[op]<(m-i)*T[m]+V[i]) op=i;
    ans=max(ans, (m-op)*T[m]+V[op]);
    dnc(s, m-1, l, op); dnc(m+1, e, op, r);
}

signed main(){
    fastio;

    cin >> N >> D;
    for (int i=1; i<=N; i++) cin >> T[i];
    for (int i=1; i<=N; i++) cin >> V[i];
    dnc(1, N, 1, N);
    cout << ans;

    return 0;
}
