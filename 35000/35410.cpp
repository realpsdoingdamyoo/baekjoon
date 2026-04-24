#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

signed main(){
    fastio;

    int N, A[1010];
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    for (int i=2; i<=N; i++) A[i]=max(A[i-1]+1, A[i]);
    cout << A[N]+1;

    return 0;
}
