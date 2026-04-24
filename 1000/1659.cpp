#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e10, bnd=1e10;

int n[2], m;
int u[2][505050], s[2][505050];
array<int, 2> v[1010101];
int dp[1010101];
map<int, int> mp;

int close(int t, int p){
    int U=u[t][lower_bound(u[t], u[t]+n[t]+1, p)-u[t]];
    int D=u[t][lower_bound(u[t], u[t]+n[t]+1, p)-u[t]-1];
    return min(U-p, p-D);
}

signed main(){
    fastio;

    cin >> n[0] >> n[1]; m=n[0]+n[1];
    for(int i=1; i<=n[0]; i++){
        cin >> u[0][i];
        s[0][i]=s[0][i-1]+u[0][i];
        v[i]={u[0][i], 0};
    }
    for(int i=1; i<=n[1]; i++){
        cin >> u[1][i];
        s[1][i]=s[1][i-1]+u[1][i];
        v[i+n[0]]={u[1][i], 1};
    }

    u[0][n[0]+1]=inf; u[1][n[1]+1]=inf;
    u[0][0]=-inf; u[1][0]=-inf;

    sort(v+1, v+m+1);

    mp[0]=0;
    int cnt[2]={0, 0};
    for(int i=1; i<=m; i++){
        int p=inf;
        int c=close(1-v[i][1], v[i][0]);
        p=min(p, c+dp[i-1]);

        cnt[v[i][1]]++;
        if(mp.find(cnt[0]-cnt[1])!=mp.end()){
            int lc=mp[cnt[0]-cnt[1]];
            int d=(i-lc)/2;
            int S[2]={s[0][cnt[0]]-s[0][cnt[0]-d], s[1][cnt[1]]-s[1][cnt[1]-d]};
            p=min(p, abs(S[0]-S[1])+dp[lc]);
        }
        mp[cnt[0]-cnt[1]]=i;
        dp[i]=p;
    }
    cout << dp[m];

    return 0;
}
