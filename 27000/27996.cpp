#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, M, A[303030], F[20], C[1<<20], G;
array<array<int, 2>, 2> DP[1<<20];

void push(array<array<int, 2>, 2>& a, array<array<int, 2>, 2> b) {
    if (a[0]<b[0]) swap(a, b);
    if (a[1]<b[0] && b[0][1]!=a[0][1]) swap(a[1], b[0]);
    if (a[1]<b[1] && b[1][1]!=a[0][1]) swap(a[1], b[1]);
}

signed main() {
    fastio;

    cin >> N >> M; G=(1<<M)-1;
    for (int i=1; i<=N; i++) for (int j=0, x; j<M; j++) cin >> x, A[i]|=x<<j, F[j]+=x;
    for (int i=1; i<1<<M; i++) C[i]=C[i&i-1]+1;

    for (int i=1; i<=N; i++) push(DP[G^A[i]], {{C[G^A[i]], i}});
    for (int i=0; i<M; i++) for (int j=(1<<M)-1; j>=0; j--) if (j&(1<<i)) push(DP[j^1<<i], DP[j]);
    for (int i=0; i<1<<M; i++) DP[i][0][0]=min(DP[i][0][0], C[i]), DP[i][1][0]=min(DP[i][1][0], C[i]);
    for (int i=0; i<M; i++) for (int j=0; j<1<<M; j++) if (~j&(1<<i)) push(DP[j|1<<i], DP[j]);

    for (int i=1; i<=N; i++) {
        int ans=0, g=0;
        for (int j=0; j<M; j++) {
            int f=F[j]-(A[i]>>j&1);
            if (f-1>=N/2) ans++;
            else if (f==N/2) g|=1<<j;
        }

        ans+=DP[g][DP[g][0][1]==i][0];
        cout << ans << "\n";
    }

    return 0;
}
