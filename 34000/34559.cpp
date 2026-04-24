#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
string S[1010];
int P[1010][1010];

void dfs(int x, int y) {
    if (x<1 || y<1 || x>N || y>M) return;
    if (S[x][y]=='1' || P[x][y]) return;

    P[x][y]=1;
    dfs(x-1, y); dfs(x+1, y);
    dfs(x, y-1), dfs(x, y+1);
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> S[i];
        S[i]=" "+S[i];
    }

    dfs(1, 1);

    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++)
        P[i][j]=P[i][j-1]+P[i-1][j]-P[i-1][j-1]+!P[i][j];


    int Q; cin >> Q;
    for (int i=1; i<=Q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int s=P[c][d]-P[c][b-1]-P[a-1][d]+P[a-1][b-1];
        if (s) cout << "No " << s << "\n"; else cout << "Yes\n";
    }


    return 0;
}
