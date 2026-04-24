#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

int N, R;
vector<int> lnk[202020];
vector<array<int, 2>> DP[202020];

void DFS(int p) {
    if (lnk[p].size()==0) {DP[p]={{1, 2}}; return;}
    int sec=0;
    for (int i : lnk[p]) {
        DFS(i);

        if (DP[i].size()>DP[p].size()) swap(DP[i], DP[p]);
        int ps=DP[p].size(), is=DP[i].size(); sec=max(sec, is);
        for (int j=0; j<is; j++) {
            DP[p][ps-j-1][0]+=DP[i][is-j-1][0];
            DP[p][ps-j-1][1]=DP[p][ps-j-1][1]*DP[i][is-j-1][1]%mod;
        }
    }
    for (int i=(int)DP[p].size()-1; i>=(int)DP[p].size()-sec; i--) R+=DP[p][i][1]-DP[p][i][0]-1, DP[p][i][1]=DP[p][i][0]+1;
    DP[p].push_back({1, 2});
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        if (i>1) lnk[a].push_back(i);
    }
    DFS(1);
    cout << (R%mod+mod)%mod;
    return 0;
}
