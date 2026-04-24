#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int C[13];
int N, R;


signed main(){
    fastio;

    for (int i=0; i<=10; i++) cin >> C[i];
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        int B, S; double L; cin >> B >> L >> S;
        if (L>=2 && S>=17) R+=C[B];
    }
    cout << R;

    return 0;
}
