#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, T, R[10101], P[10101], F[10101], G[10101];
array<int, 2> V[10101];

signed main() {
    fastio;

    cin >> N >> T;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1], R[i]=V[i][1];
    for (int i=1; i<=N; i++) P[i]=N;
    sort(V+1, V+N+1); sort(R+1, R+N+1);

    for (int i=1; i<=N; i++) F[i]=R[i], G[i]=inf;
    for (int i=N; i>=1; i--) {
        for (int j=N; R[j]>=V[i][1]; j--) {
            F[j]-=T;
            while (i<P[j] && F[j]<V[P[j]][0]) F[j]=min(F[j], G[P[j]]), P[j]--;
            if (F[j]<V[i][0]) {cout << "no"; return 0;}
            G[i]=min(G[i], F[j]-T);
        }
    }
    cout << "yes";

    return 0;
}
