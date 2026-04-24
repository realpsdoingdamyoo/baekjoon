#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, K, C[3232323], A[5050];

signed main() {
    fastio;

    cin >> K >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) {
        for (int j=1; j<i-1; j++) C[A[j]+A[i-1]]=1;
        for (int j=i+1; j<=N; j++) if (A[i]+A[j]<=K && C[K-A[i]-A[j]]) {cout << "YES"; return 0;}
    }
    cout << "NO";

    return 0;
}
