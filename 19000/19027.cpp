#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, R, C;
char V[1010][1010];
int AX, AY, BX, BY;
int P[1010][1010], K;

void DFS(int x, int y) {
    K++;
    for (array<int, 2> i : {array<int, 2>{-R, -C}, {-C, -R}, {-C, R}, {-R, C}, {R, -C}, {C, -R}, {R, C}, {C, R}}) {
        int X=x+i[0], Y=y+i[1];
        if (X<1 || Y<1 || X>N || Y>M) continue;
        if (V[X][Y]=='@' || P[X][Y]!=0) continue;
        P[X][Y]=P[x][y]^1; DFS(X, Y);
    }
}

signed main() {
    fastio;

    cin >> N >> M >> R >> C;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> V[i][j];
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        if (V[i][j]=='A') AX=i, AY=j;
        if (V[i][j]=='B') BX=i, BY=j;
    }

    P[AX][AY]=2; DFS(AX, AY);

    if (R==0 && C==0) cout << "Bob";
    else if (K==1) cout << "Bob";
    else if (P[BX][BY]==0) cout << "Alice";
    else if (P[AX][AY]==P[BX][BY]) cout << "Alice";
    else cout << "Bob";

    return 0;
}
