#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
array<int, 3> V[252525];
int P[252525];
vector<int> lnk[252525];

priority_queue<int> pq[252525];
void DFS(int p) {
    for (int i : lnk[p]) {
        DFS(i);
        if (pq[i].size()>pq[p].size()) swap(pq[p], pq[i]);
        vector<int> vec;
        while (pq[i].size()) vec.push_back(pq[i].top()+pq[p].top()), pq[p].pop(), pq[i].pop();
        for (int j : vec) pq[p].push(j);
    }
    pq[p].push(V[p][2]);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1] >> V[i][2]; V[0][1]=1e7;
    sort(V+1, V+N+1, [&](array<int, 3> a, array<int, 3> b) {return a[0]*mod-a[1]<b[0]*mod-b[1];});
    vector<int> st={0};
    for (int i=1; i<=N; i++) {
        while (V[st.back()][1]<=V[i][0]) st.pop_back();
        P[i]=st.back(); lnk[P[i]].push_back(i); st.push_back(i);
    }

    DFS(0);
    while (pq[0].size()<N) pq[0].push(0);
    int R=0;
    while (N--) R+=pq[0].top(), pq[0].pop(), cout << R << " ";

    return 0;
}
