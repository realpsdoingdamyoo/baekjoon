#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, D[2][101010], V[2][101010];
vector<array<int, 2>> lnk[101010];

void dijk(int t, int p) {
    fill(D[t]+1, D[t]+N+1, inf); D[t][p]=0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq; pq.push({0, p});
    while (pq.size()) {
        int d=pq.top()[0], x=pq.top()[1]; pq.pop();
        if (V[t][x]++) continue;
        for (array<int, 2> i : lnk[x]) if (D[t][i[0]]>D[t][x]+i[1])
            D[t][i[0]]=D[t][x]+i[1], pq.push({D[t][i[0]], i[0]});
    }
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c}); lnk[b].push_back({a, c});
    }

    dijk(0, 1); dijk(1, N);
    vector<array<int, 3>> vec, st;
    for (int i=1; i<=N; i++) vec.push_back({D[0][i], D[1][i], i});
    sort(vec.begin(), vec.end());
    for (array<int, 3> i : vec) {
        while (st.size() && st.back()[1]<=i[1]) st.pop_back();
        st.push_back(i);
    } st.push_back({-1, -1, -1});

    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        int s=0, e=st.size()-2;
        while (s<=e) {
            int m=s+e>>1;
            if (min(a*st[m][0], b*st[m][1])<min(a*st[m+1][0], b*st[m+1][1])) s=m+1;
            else e=m-1;
        }
        cout << st[s][2] << '\n';
    }

    return 0;
}
