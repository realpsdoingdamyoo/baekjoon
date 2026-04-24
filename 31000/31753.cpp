#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, A;
string s[55];
int id[55][55];

vector<int> lnk[2525];
int match[2525], cons[2525];
int L, R;

int dfs(int p) {
    for (int i : lnk[p]) {
        if (cons[i]++) continue;
        if (match[i]==-1 || dfs(match[i])) {
            match[i]=p; return true;
        }
    }
    return false;
}

int mch() {
    L=0; R=0;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (s[i][j]=='.') id[i][j]=((i^j)&1)?++L:++R;
    for (int i=1; i<=L; i++) lnk[i].clear();
    for (int i=1; i<=R; i++) match[i]=-1;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (s[i][j]=='.' && ((i^j)&1)) {
        if (i>1 && s[i-1][j]=='.') lnk[id[i][j]].push_back(id[i-1][j]);
        if (i<N && s[i+1][j]=='.') lnk[id[i][j]].push_back(id[i+1][j]);
        if (j>1 && s[i][j-1]=='.') lnk[id[i][j]].push_back(id[i][j-1]);
        if (j<M && s[i][j+1]=='.') lnk[id[i][j]].push_back(id[i][j+1]);
    }

    int ret=0;
    for (int i=1; i<=L; i++) {
        for (int j=1; j<=R; j++) cons[j]=0;
        if (dfs(i)) ret++;
    }

    return ret;
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) {cin >> s[i]; s[i]=" "+s[i];}

    int cnt=mch();

    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (s[i][j]=='.') {
        s[i][j]='#'; if (mch()==cnt) A++; s[i][j]='.';
    }
    cout << A;

    return 0;
}
