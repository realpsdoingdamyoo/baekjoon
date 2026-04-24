#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

const double pi=acos(-1);

int N, M;
double P[1010], ans;

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            int a; cin >> a;
            P[i]+=a;
        }
        P[i]/=M;
    }

    for (int i=1; i<=N; i++) {
        ans+=P[i]/N;
    }

    cout.precision(11);
    cout << ans;

    return 0;
}
