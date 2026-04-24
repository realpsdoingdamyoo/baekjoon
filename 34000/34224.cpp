#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, ans;
vector<array<int, 2>> lnk[505050];
unordered_map<int, int> mp[505050];
int lzy[505050];

void dfs(int p, int pre) {
    for (array<int, 2> i : lnk[p]) if (i[0]!=pre) {
        dfs(i[0], p);
        if (mp[i[0]].size()>mp[p].size()) {
            for (pair<int, int> j : mp[p]) {
                ans+=mp[i[0]][j.first^lzy[p]^lzy[i[0]]^i[1]]*j.second;
                mp[i[0]][j.first^lzy[p]^lzy[i[0]]^i[1]]+=j.second;
            } swap(mp[p], mp[i[0]]); lzy[p]=lzy[i[0]]^i[1];
        }
        else {
            for (pair<int, int> j : mp[i[0]]) {
                ans+=mp[p][j.first^lzy[p]^lzy[i[0]]^i[1]]*j.second;
                mp[p][j.first^lzy[p]^lzy[i[0]]^i[1]]+=j.second;
            }
        }
    }
    ans+=mp[p][lzy[p]]; mp[p][lzy[p]]++;
}

signed main(){
    fastio;

    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    dfs(1, 0);

    cout << ans << "\n";


    return 0;
}
