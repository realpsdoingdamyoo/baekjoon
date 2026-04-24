#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Z, Q;
int V[252525];
int P[252525][20], D[252525];
array<int, 2> S[252525][20];

array<int, 2> lca(int a, int b) {
    int d=0;
    if (D[a]>D[b]) {d++; a=P[a][0];}
    if (a==b) return {a, d};
    for (int i=19; i>=0; i--) {
        if (P[a][i]==P[b][i]) continue;
        a=P[a][i]; b=P[b][i]; d+=2<<i;
    }
    return {P[a][0], d+2};
}

int sp(int s, int e) {
    int ret=0;
    for (int i=19; i>=0; i--) if (P[s][i]<=e) {
        ret+=D[s]-D[P[s][i]]; s=P[s][i];
    }
    return ret+(s<=e);
}

void solve() {
    cin >> N >> Z;
    for (int i=1; i<=N; i++) cin >> V[i];
    D[N+1]=0;
    for (int i=0; i<20; i++) P[N+1][i]=N+1, S[N+1][i]={N+1, 0};

    for (int i=N; i>=1; i--) {
        P[i][0]=lower_bound(V+1, V+N+1, V[i]+Z+1)-V;
        D[i]=D[P[i][0]]+1;
        for (int j=1; j<20; j++) P[i][j]=P[P[i][j-1]][j-1];
    }

    for (int i=N; i>=1; i--) {
        S[i][0]=lca(i, i+1);
        for (int j=1; j<20; j++) {
            S[i][j][0]=S[S[i][j-1][0]][j-1][0];
            S[i][j][1]=S[i][j-1][1]+S[S[i][j-1][0]][j-1][1];
        }
    }

    cin >> Q;
    for (int i=1; i<=Q; i++) {
        int A, B, R=0; cin >> A >> B;
        for (int j=19; j>=0; j--) {
            if (S[A][j][0]<=B) {
                R+=S[A][j][1];
                A=S[A][j][0];
            }
        }
        R+=sp(A, B)+sp(A+1, B);
        cout << R << "\n";
    }

}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();


    return 0;
}
