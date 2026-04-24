#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

const int X=10;
int V[1<<X][1<<X];
int seg[2<<X][2<<X];

void update(int x, int y, int c) {
    x+=1<<X; y+=1<<X;
    for (int i=0; i<=X; i++) for (int j=0; j<=X; j++) seg[x>>i][y>>j]+=c;
}

int sum(int s1, int e1, int s2, int e2) {
    int r=0;
    s1+=1<<X; e1+=1<<X; s2+=1<<X; e2+=1<<X;
    for (int i=X; i>=0; i--) for (int j=X; j>=0; j--) {
        int S1=(s1-1>>i)+1, E1=(e1+1>>i)-1;
        int S2=(s2-1>>j)+1, E2=(e2+1>>j)-1;
        if (S1>E1 || S2>E2) continue;
        if ((S1&1) && (S2&1)) r+=seg[S1][S2];
        if ((S1&1) && !(E2&1)) r+=seg[S1][E2];
        if (!(E1&1) && (S2&1)) r+=seg[E1][S2];
        if (!(E1&1) && !(E2&1)) r+=seg[E1][E2];
    }
    return r;
}

signed main() {
    fastio;

    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> V[i][j], seg[i+(1<<X)][j+(1<<X)]=V[i][j];
    for (int i=(2<<X)-1; i>=1; i--) for (int j=(2<<X)-1; j>=(1<<X); j--) seg[i>>1][j]+=seg[i][j];
    for (int i=(2<<X)-1; i>=1; i--) for (int j=(2<<X)-1; j>=1; j--) seg[i][j>>1]+=seg[i][j];

    for (int i=1; i<=M; i++) {
        int t; cin >> t;
        if (t==1) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            cout << sum(a-1, c-1, b-1, d-1) << "\n";
        }
        else {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            update(a, b, c-V[a][b]); V[a][b]=c;
        }
    }

    return 0;
}
