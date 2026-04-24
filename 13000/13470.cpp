#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
int X[210], Y[210];

vector<int> lnk[110];
int C[210], M[210];

bool dfs(int p) {
    for (int i : lnk[p]) if (!C[i]) {
        C[i]=1;
        if (M[i]==0 || dfs(M[i])) {
            M[i]=p; return true;
        }
    }
    return false;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N*2; i++) cin >> X[i] >> Y[i];

    int S=0, E=5e8;
    while (S<=E) {
        int R=S+E>>1;
        for (int i=1; i<=N; i++) lnk[i].clear();
        for (int i=1; i<=N; i++) for (int j=N+1; j<=N*2; j++)
            if (abs(X[i]-X[j])+abs(Y[i]-Y[j])<=R)
                lnk[i].push_back(j);

        int P=1;
        for (int i=N+1; i<=N*2; i++) M[i]=0;
        for (int i=1; i<=N; i++) {
            for (int j=N+1; j<=N*2; j++) C[j]=0;
            if (!dfs(i)) {P=0; break;}
        }
        if (P) E=R-1; else S=R+1;
    }
    cout << S;

    return 0;
}
