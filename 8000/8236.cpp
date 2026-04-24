#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, K, A, B;
set<int> lnk[101010], lnk2[101010];
int D[101010], R[101010], q[101010];

signed main() {
    fastio;

    cin >> N >> M >> K >> A >> B;
    fill(D+1, D+N+1, inf); D[K]=0; q[1]=K;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].insert(b); lnk[b].insert(a);
        lnk2[a].insert(b); lnk2[b].insert(a);
    }
    for (int s=1, e=1; s<=e; s++) {
        for (int i : lnk[q[s]]) if (D[i]==inf)
            q[++e]=i, D[i]=D[q[s]]+1;
    }
    for (int i=1; i<=N; i++) R[i]=(D[i]/2)*min(A*2, B)+(D[i]%2)*A;

    fill(D+1, D+N+1, inf); D[K]=0; q[1]=K;
    for (int s=1, e=1; s<=e; s++) {
        for (int i : lnk[q[s]]) {
            int j=-inf;
            while (lnk2[i].size() && j<*prev(lnk2[i].end())) {
                j=*lnk2[i].upper_bound(j);
                if (D[j]==inf && lnk[q[s]].find(j)==lnk[q[s]].end()) {
                    lnk2[i].erase(lnk2[i].find(j));
                    q[++e]=j, D[j]=D[q[s]]+1;
                    for (int k : lnk[j]) if (lnk2[k].find(j)!=lnk2[k].end()) lnk2[k].erase(lnk2[k].find(j));
                }
            }
        }
    }
    for (int i=1; i<=N; i++) cout << min(R[i], D[i]*B) << "\n";


    return 0;
}
