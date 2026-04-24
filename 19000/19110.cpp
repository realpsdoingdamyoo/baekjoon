#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
array<int, 2> V[101010], P[101010];

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1];
    for (int i=1; i<=N; i++) P[i*2-1]={V[i][0], 1}, P[i*2]={V[i][1], -1};
    sort(P+1, P+N*2+1);

    vector<int> st;
    int C=0, M=0;

    for (int i=1; i<=N*2; i++) {
        M-=P[i][0]*P[i][1];
        if (P[i][1]==-1) st.push_back(P[i][0]);
        else if (st.size()) M+=P[i][0]-st.back(), st.pop_back();
        else C++;
    }
    cout << C << " " << M << "\n";
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
