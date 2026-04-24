#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, M, X, Y, A;
char V[110][110];

void dfs(int x, int y) {
    A++; V[x][y]='.';
    for (int i=-1; i<=1; i++) for (int j=-1; j<=1; j++) if (i*i+j*j==1 && V[i+x][j+y]=='#')
        dfs(x+i, y+j);
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> V[i][j]; if (V[i][j]=='S') X=i, Y=j;
    }

    dfs(X, Y);
    cout << A;

    return 0;
}
