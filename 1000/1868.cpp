#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N, DP[50505];
vector<int> lnk[50505];

bool chk(int K, priority_queue<int> pq, int X) {
    pq.push(X);

    while (K>=0) {
        if (pq.top()<1<<K) return true;
        pq.push(pq.top()-(1<<K)); pq.pop();
        K--;
    }
    return false;
}

void dfs(int p, int x) {
    int K=0;
    priority_queue<int> pq;

    for (int i : lnk[p]) if (i!=x) dfs(i, p), pq.push(DP[i]);

    if (pq.size()==0) {
        DP[p]=1; return;
    }
    K=32-__builtin_clz(pq.top());

    int s=0, e=(1<<K+1);

    while (s<=e) {
        int m=s+e>>1;
        if (chk(K, pq, m)) s=m+1;
        else e=m-1;
    }
    DP[p]=(1<<K+1)-s;
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    dfs(1, 0);

    cout << 31-__builtin_clz(DP[1]);

    return 0;
}
