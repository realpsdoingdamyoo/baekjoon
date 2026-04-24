#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
int v[405][405];

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        string s; cin >> s;
        for (int j=1; j<=M; j++) v[i][j]=(s[j-1]=='.')*(v[i-1][j]+1);
    }

    int ans=0;
    for (int i=1; i<=N; i++) for (int d=1; d<=N; d++) {
        int mln=0, cur=0;
        for (int j=1; j<=M; j++) {
            if (v[i][j]>=d) mln=max(mln, ++cur);
            else cur=0;
        }
        if (mln) ans=max(mln*2+d*2, ans);
    }

    cout << (ans-!!ans);

    return 0;
}
