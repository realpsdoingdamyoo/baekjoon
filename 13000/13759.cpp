#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=6969747469, inf=1e18;

int N, A[101010], DP[1<<20], G[101010]={1}, R;

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) G[i]=G[i-1]*2%mod, cin >> A[i], DP[A[i]]++;
    for (int i=0; i<20; i++) for (int j=0; j<1<<20; j++) if (j&(1<<i)) DP[j^1<<i]+=DP[j];
    for (int i=0; i<1<<20; i++) DP[i]=G[DP[i]]-!!i;
    for (int i=0; i<20; i++) for (int j=0; j<1<<20; j++) if (j&(1<<i)) DP[j^1<<i]-=DP[j];
    for (int i=0; i<1<<20; i++) R+=!!(DP[i]%mod);
    cout << R;

    return 0;
}
