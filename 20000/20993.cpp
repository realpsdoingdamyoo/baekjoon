#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, Q;
bool C[1010][1010];
int P[2020];

void DFS(int x, int y) {
    if (x<1 || y<1 || x>N || y>M) return;
    if (x==1 && y==1) return;
    if (x==N && y==M) return;
    if (C[x][y]) {
        if (!C[x-1][y]) DFS(x-1, y);
        if (!C[x+1][y]) DFS(x+1, y);
        if (!C[x][y-1]) DFS(x, y-1);
        if (!C[x][y+1]) DFS(x, y+1);
        return;
    }

    if (C[x-1][y] && C[x][y-1]) {
        C[x][y]=1; P[x+y]--;
        if (!C[x+1][y]) DFS(x+1, y);
        if (!C[x][y+1]) DFS(x, y+1);
        return;
    }

    if (C[x+1][y] && C[x][y+1]) {
        C[x][y]=1; P[x+y]--;
        if (!C[x-1][y]) DFS(x-1, y);
        if (!C[x][y-1]) DFS(x, y-1);
    }
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=0; i<=N+1; i++) for (int j=0; j<=M+1; j++) C[i][j]=1;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> C[i][j]; P[i+j]+=1-C[i][j];
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) DFS(i, j);

    cin >> Q;
    for (int t=1; t<=Q; t++) {
        int x, y; cin >> x >> y;
        if (C[x][y]) cout << "1\n";
        else if (P[x+y]==1) cout << "0\n";
        else {
            cout << "1\n";
            C[x][y]=1; P[x+y]--; DFS(x, y);
        }

        /*for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) cout << C[i][j] << " ";
            cout << "\n";
        }
        for (int i=2; i<=N+M; i++) cout << P[i] << " "; cout << "\n";*/
    }

    return 0;
}
