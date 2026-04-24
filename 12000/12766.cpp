#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, B, S, R;
vector<array<int, 2>> lnk[2][5050];
int V[2][5050], D[2][5050], G[5050];

int DP[5050], F[5050];

void dnc(int s, int e, int l, int r) {
    if (s>e) return;
    array<int, 2> rt={inf, inf};
    int m=s+e>>1;
    for (int i=min(r, m-1); i>=l; i--) rt=min(rt, {DP[i]+(G[m]-G[i])*(m-i-1), i});
    F[m]=rt[0]; dnc(s, m-1, l, rt[1]); dnc(m+1, e, rt[1], r);
}

signed main() {
    fastio;

    cin >> N >> B >> S >> R;
    for (int i=1; i<=R; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[0][a].push_back({b, c}); lnk[1][b].push_back({a, c});
    }

    for (int t : {0, 1}) {
        fill(D[t]+1, D[t]+N+1, inf); D[t][B+1]=0;
        priority_queue<array<int, 2>> pq; pq.push({0, B+1});
        while (pq.size()) {
            int d=pq.top()[0], p=pq.top()[1]; pq.pop();
            if (V[t][p]++) continue;
            for (array<int, 2> i : lnk[t][p])
                D[t][i[0]]=min(D[t][i[0]], i[1]-d), pq.push({d-i[1], i[0]});
        }
    }

    for (int i=1; i<=B; i++) G[i]=D[0][i]+D[1][i];
    sort(G+1, G+B+1);

    for (int i=1; i<=B; i++) G[i]=G[i-1]+G[i];
    for (int i=1; i<=B; i++) DP[i]=G[i]*(i-1);

    for (int i=2; i<=S; i++) dnc(i, B, i-1, B), swap(DP, F);

    cout << DP[B];


    return 0;
}
