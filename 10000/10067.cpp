#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, K, C, S[101010];
int DP[2][101010];
signed P[101010][202], H[101010];
vector<array<int, 3>> st;

int crs(array<int, 3> a, array<int, 3> b) {
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> S[i], S[i]+=S[i-1], DP[0][i]=S[i]*S[i];

    for (int j=1; j<=K; j++) {
        int p=0;
        st={{0, 0, 0}};
        for (int i=1; i<=N; i++) {
            while (p+1<st.size() && st[p][0]*S[i]+st[p][1]>=st[p+1][0]*S[i]+st[p+1][1]) p++;
            DP[1][i]=st[p][0]*S[i]+S[i]*S[i]+st[p][1]; P[i][j]=st[p][2];
            array<int, 3> cs={-2*S[i], DP[0][i]+S[i]*S[i], i};
            while (p+1<st.size() && crs(st[st.size()-2], st.back())>=crs(st.back(), cs)) st.pop_back();
            st.push_back(cs);
        }
        swap(DP[0], DP[1]);
    }
    cout << (S[N]*S[N]-DP[0][N])/2 << "\n";
    vector<int> ans;
    while (K) N=P[N][K], ans.push_back(N), K--;
    while (ans.size()) cout << ans.back() << " ", ans.pop_back();
    return 0;
}
