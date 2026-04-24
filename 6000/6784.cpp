#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

char a[10101], b[10101];

signed main(){
    fastio;

    int N, A=0; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=N; i++) cin >> b[i], A+=(a[i]==b[i]);
    cout << A;

    return 0;
}
