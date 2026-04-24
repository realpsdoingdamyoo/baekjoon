#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int P[505050], M=500050;

int N, Q, A[202020], B[202020];

signed main() {
    fastio;

    for (int i=1; i<=M; i++) P[i]=i;
    for (int i=2; i<=M; i++) for (int j=i; j<=M; j+=i) P[j]=min(P[j], i);

    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1, a, b; i<=Q; i++) cin >> a >> b, B[a]++, B[b+1]--;
    for (int i=1; i<=N; i++) B[i]+=B[i-1];

    double ans=0;
    for (int i=1; i<=N; i++) {
        if (B[i]==0) {ans+=A[i]; continue;}
        set<int> g;
        while (A[i]>1) g.insert(P[A[i]]), A[i]/=P[A[i]];

        int s=0, c=0;
        for (int j : g) s+=j, c++;
        ans+=(s+0.0)/c;
    }

    cout.precision(10);
    cout << ans;


    return 0;
}
