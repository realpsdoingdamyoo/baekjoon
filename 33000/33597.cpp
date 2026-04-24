#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
int W[55][55];
vector<vector<int>> ans;

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=K; i++) {
        int a, b; cin >> a >> b;
        W[a][b]=1; W[b][a]=-1;
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) if (W[i][j]==0) W[i][j]=1, W[j][i]=-1;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<ans.size()/2; j++) ans[j].insert(ans[j].begin(), i);
        for (int j=ans.size()/2; j<ans.size(); j++) ans[j].push_back(i);

        vector<int> nvc1, nvc2;
        for (int j=1; j<i; j++) if (W[j][i]==1) nvc1.push_back(j), nvc2.push_back(j);
        nvc2.push_back(i);
        for (int j=1; j<i; j++) if (W[j][i]==-1) nvc1.push_back(j), nvc2.push_back(j);
        reverse(nvc1.begin(), nvc1.end());

        ans.push_back(nvc2);
        ans.push_back(nvc2);
        ans.push_back(nvc1); ans.back().push_back(i);
        nvc1.insert(nvc1.begin(), i); ans.push_back(nvc1);
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (vector<int> i : ans) {
        for (int j : i) cout << j << " ";
        cout << "\n";
    }


    return 0;
}
