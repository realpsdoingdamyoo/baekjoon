#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int K, A[110];
 
struct vil {
    int N, M;
    vector<int> lnk[550];
 
    void input() {
        cin >> N >> M;
        for (int i=1; i<=M; i++) {
            int a, b; cin >> a >> b;
            lnk[a].push_back(b); lnk[b].push_back(a);
        }
    }
 
    int D[550][550], G;
    void bfs() {
        for (int p=1; p<=N; p++) {
            for (int i=1; i<=N; i++) D[p][i]=inf;
            D[p][p]=0;
 
            queue<int> q; q.push(p);
 
            while (q.size()) {
                int x=q.front(); q.pop();
                for (int i : lnk[x]) if (D[p][i]==inf)
                    D[p][i]=D[p][x]+1, q.push(i);
            }
        }
 
        G=inf;
 
        for (int i=1; i<=N; i++) {
            int g=0;
            for (int j=1; j<=N; j++) g=max(g, D[i][j]);
            G=min(G, g);
        }
    }
} V[110];
 
signed main() {
    fastio;
 
    cin >> K;
    for (int i=1; i<=K; i++) V[i].input(), V[i].bfs();
 
    for (int i=1; i<=K; i++) A[i]=V[i].G;
    sort(A+1, A+K+1); reverse(A+1, A+K+1);
 
    int ans=A[1];
    for (int i=1; i*2<=K; i++) ans=max(ans, i+A[i*2]);
    for (int i=1; i*2+1<=K; i++) ans=max(ans, i+A[i*2+1]);
 
    cout << ans;
 
    return 0;
}
