#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
vector<array<int, 2>> lnk[252525];
array<array<int, 2>, 2> DP[252525];

void DFS(int p, int x, int m, int pl) {
    array<int, 2> ret={}, add={};
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        DFS(i[0], p, m, i[1]);
        ret[0]+=DP[i[0]][0][0]; ret[1]+=DP[i[0]][0][1];
        add=max(add, {DP[i[0]][1][0]-DP[i[0]][0][0], DP[i[0]][1][1]-DP[i[0]][0][1]});
    }
    DP[p]={array<int, 2>{ret[0]+add[0], ret[1]+add[1]}, {ret[0]+pl+m, ret[1]+1}};
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    int s=-1e12, e=1e12;
    while (s<=e) {
        int m=(s+e)/2;
        DFS(1, 0, m, -inf);
        if (DP[1][0][1]<K) s=m+1; else e=m-1;
    }

    if (s==1e12+1) cout << "Impossible";
    else {
        DFS(1, 0, s, -inf);
        cout << DP[1][0][0]-K*s;
    }



    return 0;
}
