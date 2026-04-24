#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, x, y;
bool X[1010][1010];

signed main(){
    fastio;

    cin >> x >> y >> N;
    for (int i=1; i<=N; i++) {
        int a, b; cin >> a >> b;
        X[a][b]=1;
    }

    double ans=0;
    for (int i=0; i<x; i++) for (int j=0; j<y; j++) {
        if (X[i][j] && X[i+1][j+1]) ans+=1;
        else if (X[i+1][j] && X[i][j+1]) ans+=1;
        else if (0LL+X[i][j]+X[i][j+1]+X[i+1][j]+X[i+1][j+1]==2) ans+=0.95661147749051819645;
        else if (0LL+X[i][j]+X[i][j+1]+X[i+1][j]+X[i+1][j+1]==1) ans+=0.78539816339744830961;
    }
    cout.precision(10);
    cout << ans;

    return 0;
}
