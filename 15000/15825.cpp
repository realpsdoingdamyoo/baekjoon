#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

const int MX=500050;
int N, A[20202], T, S[MX+10];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    cin >> T;
    for (int t=1; t<=N; t++) {
        int X=A[t];
        for (int i=1, j; i<=X; i=j+1) {
            j= i==X ? MX : (X-1)/((X-1)/i);
            S[i]+=(X-1)/i+1; S[j+1]-=(X-1)/i+1;
        }
    }
    array<int, 2> ans={inf, inf};
    for (int i=1; i<=MX; i++) {
        S[i+1]+=S[i];
        ans=min(ans, {(T+i)*S[i], i});
    }
    cout << ans[0] << " " << ans[1];

    return 0;
}
