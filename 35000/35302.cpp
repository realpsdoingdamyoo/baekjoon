#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, K, ans;
array<int, 2> V[202020];

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=K; i++) {
        int C, A; cin >> C >> A;
        ans+=A*(C-1);
        V[i]={A*2, C/2+1};
    }
    sort(V+1, V+K+1, [&](array<int, 2> a, array<int, 2> b){return a[0]*b[1]>b[0]*a[1];});
    int S=1;
    for (int i=1; i<=K; i++) ans+=S*V[i][0], S+=V[i][1];
    cout << ans;

    return 0;
}
