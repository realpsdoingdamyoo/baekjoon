#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, R;
int V[303030];
int sp[303030][80];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i], sp[i][0]=-1;
    for (int j=1; j<80; j++) {
        sp[0][j-1]=sp[N+1][j-1]=-1;
        for (int i=1; i<=N; i++) {
            if (V[i]==j) sp[i][j]=i;
            else sp[i][j]=sp[sp[i][j-1]+1][j-1];
        }
    }

    for (int i=1; i<=N; i++) for (int j=1; j<80; j++) if (sp[i][j]!=-1) R=max(R, j);
    cout << R;

    return 0;
}
