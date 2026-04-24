#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, A;
string s[110], res[110];
int id[110][110];

vector<int> lnk[10101];
int mt[10101], cs[10101], F[10101];
int L, R, X;

int dfs(int p) {
    for (int i : lnk[p]) {
        if (i==X || cs[i]++) continue;
        if (!mt[i] || dfs(mt[i])) {
            mt[i]=p; F[p]=1; return true;
        }
    }
    return false;
}

bool solve() {
    cin >> N >> M;
    if (!N) return false;
    for (int i=1; i<=N; i++) {cin >> s[i]; res[i]=s[i]=" "+s[i];}

    for (int t : {0, 1}) {
        L=0; R=0; X=0;
        for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (s[i][j]=='.') id[i][j]=((i^j)&1)==t?++L:++R;
        for (int i=1; i<=L; i++) lnk[i].clear(), F[i]=0;
        for (int i=1; i<=R; i++) mt[i]=0;
        for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (s[i][j]=='.' && ((i^j)&1)==t) {
            if (i>1 && s[i-1][j]=='.') lnk[id[i][j]].push_back(id[i-1][j]);
            if (i<N && s[i+1][j]=='.') lnk[id[i][j]].push_back(id[i+1][j]);
            if (j>1 && s[i][j-1]=='.') lnk[id[i][j]].push_back(id[i][j-1]);
            if (j<M && s[i][j+1]=='.') lnk[id[i][j]].push_back(id[i][j+1]);
        }
        int cnt=0;
        for (int i=1; i<=L; i++) {
            fill(cs+1, cs+R+1, 0);
            if (dfs(i)) cnt++;
        }

        for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (s[i][j]=='.') if (((i^j)&1)!=t) {
            int p=id[i][j];
            fill(cs+1, cs+R+1, 0);
            if (!mt[p]) res[i][j]='B';
            else {
                int pr=mt[p]; mt[p]=0; X=p;
                if (dfs(pr)) res[i][j]='B';
                else fill(cs+1, cs+R+1, 0), X=0, dfs(pr), res[i][j]='A';
            }
        }
        for (int i=1; i<=R; i++) cnt-=!!mt[i];
        assert(cnt==0);
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cout << res[i][j];
        cout << "\n";
    }
    cout << "\n";

    return true;
}

signed main(){
    fastio;
    while (solve()){}

    return 0;
}
