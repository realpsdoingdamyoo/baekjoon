#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, M, A[110];
vector<int> lnk[110];

bool solve(int t) {
    cin >> N;
    if (!N) return false;
    cin >> M;
    for (int i=1; i<=N; i++) lnk[i].clear();
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    if (M!=N-1) {cout << "Graph " << t << " is not a caterpillar.\n"; return true;}

    for (int i=1; i<=N; i++) A[i]=lnk[i].size()>1;
    int C[3]={};
    for (int i=1; i<=N; i++) if (A[i]) {
        int cnt=0;
        for (int j : lnk[i]) if (A[j]) cnt++;
        if (cnt>=3) {cout << "Graph " << t << " is not a caterpillar.\n"; return true;}
        C[cnt]++;
    }

    if (C[0] || C[1]==2) cout << "Graph " << t << " is a caterpillar.\n";
    else cout << "Graph " << t << " is not a caterpillar.\n";
    return true;
}

signed main(){
    fastio;

    for (int t=1;; t++) if (!solve(t)) break;

    return 0;
}
