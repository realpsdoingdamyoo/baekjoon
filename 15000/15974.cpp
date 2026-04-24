#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int n;
array<int, 2> ans, v[3030];
vector<array<int, 2>> dp[3030][2];
vector<int> ord[3030];

int ccw(int a, int b, int c) {return v[a][0]*v[b][1]+v[b][0]*v[c][1]+v[c][0]*v[a][1]-v[a][1]*v[b][0]-v[b][1]*v[c][0]-v[c][1]*v[a][0];}

int Find0(int p, int x) {
    if (dp[x][1].size()==0 || ccw(dp[x][1][0][1], x, p)<=0) return 0;
    int s=0, e=dp[x][1].size()-1;
    while (s<=e) {
        int m=s+e>>1;
        if (ccw(dp[x][1][m][1], x, p)>0) s=m+1; else e=m-1;
    }
    return dp[x][1][e][0];
}
int Find1(int p, int x) {
    if (dp[x][0].size()==0 || ccw(dp[x][0][0][1], x, p)>=0) return 0;
    int s=0, e=dp[x][0].size()-1;
    while (s<=e) {
        int m=s+e>>1;
        if (ccw(dp[x][0][m][1], x, p)<0) s=m+1; else e=m-1;
    }
    return dp[x][0][e][0];
}

double ang(int a, int b, int c) {
    double ab=(v[a][0]-v[b][0])*(v[a][0]-v[b][0])+(v[a][1]-v[b][1])*(v[a][1]-v[b][1]);
    double bc=(v[b][0]-v[c][0])*(v[b][0]-v[c][0])+(v[b][1]-v[c][1])*(v[b][1]-v[c][1]);
    double ca=(v[c][0]-v[a][0])*(v[c][0]-v[a][0])+(v[c][1]-v[a][1])*(v[c][1]-v[a][1]);
    return -abs(ab+bc-ca)*(ab+bc-ca)/(4*ab*bc);
}


signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[1]<b[1];});
    sort(v+2, v+n+1, [&](array<int, 2> a, array<int, 2> b) {return (a[1]-v[1][1])*(b[0]-v[1][0])>(b[1]-v[1][1])*(a[0]-v[1][0]);});
    for (int i=2; i<=n-2; i++) {
        if (ccw(i, i+1, i+2)>0) break;
        if (i==n-2){cout << "0"; return 0;}
    }

    for (int i=3; i<=n; i++) {
        for (int j=1; j<i; j++) ord[i].push_back(j);
        sort(ord[i].begin(), ord[i].end(), [&](int a, int b){return ang(a, i, 1)<ang(b, i, 1);});
    }

    for (int i=2; i<=n; i++) {
        vector<array<int, 2>> dpr[2];
        dpr[0].push_back({1, 1});

        for (int j : ord[i]) {
            if (ccw(i, j, 1)==0) continue;
            dpr[0].push_back({Find0(i, j)+1, j});
            dpr[1].push_back({Find1(i, j)+1, j});
            ans=max(ans, {dpr[0].back()[0], i});
        } reverse(dpr[1].begin(), dpr[1].end());

        for (array<int, 2> j : dpr[0]) if (dp[i][0].size()==0 || dp[i][0].back()[0]<j[0]) dp[i][0].push_back(j);
        for (array<int, 2> j : dpr[1]) if (dp[i][1].size()==0 || dp[i][1].back()[0]<j[0]) dp[i][1].push_back(j);
    }

    cout << ans[0]+1 << "\n";
    int p=ans[1], c=0, r=ans[0];
    vector<array<int, 2>> Ans;
    while (p!=1) {
        Ans.push_back(v[p]);
        for (array<int, 2> i : dp[p][c]) {
            if (i[0]==r) {r--; c^=1; p=i[1]; break;}
        }
    }

    cout << v[1][0] << " " << v[1][1] << "\n";
    for (array<int, 2> i : Ans) cout << i[0] << " " << i[1] << "\n";

    return 0;
}
