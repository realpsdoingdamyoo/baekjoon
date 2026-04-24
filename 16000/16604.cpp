#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int N, M, A, B;
vector<array<int, 2>> lnk[2][101010];


int D[2][101010], vis[2][202020];

void dijk(int t, int p) {
    fill(D[t]+1, D[t]+N+1, inf); D[t][p]=0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, p});

    while (pq.size()) {
        int d=pq.top()[0], x=pq.top()[1]; pq.pop();
        if (vis[t][x]++) continue; D[t][x]=d;
        for (array<int, 2> i : lnk[t][x]) pq.push({i[1]+d, i[0]});
    }
}

int PU[202020], CV[202020], se[202020], mtd[202020], dis[202020], rdg[202020];
vector<array<int, 2>> gr[202020];


bool chk(int d) {
    for (int i=1; i<=N; i++) PU[i]=CV[i]=se[i]=mtd[i]=dis[i]=rdg[i]=0, gr[i].clear();

    for (int i=1; i<=N; i++) {
        if (D[1][i]<=d) PU[i]=1;
        if (D[0][i]<=A) CV[i]=1;
    }
    for (int i=1; i<=N; i++) if (PU[i]) {
        for (array<int, 2> j : lnk[1][i]) if (!PU[j[0]]) {
            if (D[0][j[0]]+j[1]-(d-D[1][i])<=A) {
                CV[i]=1; mtd[i]=max(mtd[i], d-D[1][i]);
            }
        }
    }

    for (int i=1; i<=N; i++) if (PU[i]) {
        for (array<int, 2> j : lnk[0][i]) {
            if (j[1]+D[1][j[0]]<=d) {
                gr[j[0]].push_back({i, j[1]});
                rdg[i]++;
            }
        }
    }

    vector<int> st;
    for (int i=1; i<=N; i++) if (!rdg[i]) st.push_back(i);
    while (st.size()) {
        int p=st.back(); st.pop_back(); se[p]=1;
        for (array<int, 2> i : gr[p]) {
            dis[i[0]]=max(dis[i[0]], dis[p]+i[1]);
            if (!--rdg[i[0]]) st.push_back(i[0]);
        }
    }

    for (int i=1; i<=N; i++) if (PU[i] && CV[i] && (!se[i] || mtd[i]+dis[i]>=B-A)) return true;
    return false;

}

signed main(){
    fastio;

    cin >> A >> B >> N >> M;
    for (int i=1; i<=M; i++) {
        int x, y, z; cin >> x >> y >> z;
        lnk[0][x].push_back({y, z});
        lnk[1][y].push_back({x, z});
    }

    dijk(0, 1); dijk(1, N);

    int s=0, e=1e14;
    while (s<=e) {
        int m=s+e>>1;
        if (chk(m)) e=m-1; else s=m+1;
    }
    cout << min({D[0][N], max(D[0][N], B)-A, s});

    return 0;
}
