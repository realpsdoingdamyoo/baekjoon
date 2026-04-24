#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N;
vector<int> lnk[101010];
array<int, 3> DP[101010];
array<int, 2> RR[101010];

void dfs(int p, int x) {
    for (int i : lnk[p]) if (i!=x) {
        dfs(i, p);
        DP[p][0]+=DP[i][0];
        DP[p][1]+=DP[i][0]*DP[i][0];
        DP[p][2]+=DP[i][2]+DP[i][0];
    }
    DP[p][2]+=DP[p][0]*DP[p][0]-DP[p][1]; DP[p][0]++;
}

void rrt(int p, int x) {
    int s=N-DP[p][0], ss=s*s, s2=RR[p][1];
    for (int i : lnk[p]) if (i!=x) {
        s+=DP[i][0]; ss+=DP[i][0]*DP[i][0]; s2+=DP[i][2]+DP[i][0];
    }
    for (int i : lnk[p]) if (i!=x) {
        s-=DP[i][0]; ss-=DP[i][0]*DP[i][0]; s2-=DP[i][2]+DP[i][0];
        RR[i]={s+1, s*s-ss+s2+(s+1)};
        rrt(i, p);
        s+=DP[i][0]; ss+=DP[i][0]*DP[i][0]; s2+=DP[i][2]+DP[i][0];
    }

}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    dfs(1, 0);
    rrt(1, 0);

    int ans=inf;
    for (int i=1; i<=N; i++) ans=min(ans, 2*(DP[i][0]-1)*RR[i][0]+DP[i][2]+RR[i][1]);
    cout << ans;

    return 0;
}
