#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, w;
array<int, 5> mat[3030];
vector<int> mL[6060];
int dp[3030][6060];

bool meet(array<int, 5>& a, array<int, 5>& b){
    if(max(a[0], b[0])>=min(a[1], b[1])) return false;
    if(max(a[2], b[2])>=min(a[3], b[3])) return false;
    return true;
}


signed main(){
    fastio;

    cin >> n >> w;
    for(int i=0; i<n; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if(a==0) mat[i]={b, c, w-d, w, e};
        else mat[i]={b, c, 0, d, e};
    }

    map<int, int> mp;
    for(int i=0; i<n; i++) for(int j : {0, 1}) mp[mat[i][j]]=0;
    int c=0; for(pair<int, int> i : mp) mp[i.first]=++c;
    for(int i=0; i<n; i++) for(int j : {0, 1}) mat[i][j]=mp[mat[i][j]];
    sort(mat, mat+n);

    for(int i=0; i<n; i++) mL[mat[i][0]].push_back(i);

    int ret=0;
    for(int i=0; i<n; i++) dp[i][0]=mat[i][4];
    for(int i=0; i<n; i++) for(int j=1; j<=c; j++){
        dp[i][j]=max(dp[i][j], dp[i][j-1]);

        for(int p : mL[j]){
            if(meet(mat[i], mat[p])) continue;
            if(mat[p][1]<mat[i][1]) dp[i][mat[p][1]]=max(dp[i][mat[p][1]], dp[i][j]+mat[p][4]);
            else dp[p][mat[i][1]]=max(dp[p][mat[i][1]], dp[i][j]+mat[p][4]);
        }
        ret=max(ret, dp[i][j]);
    }

    cout << ret;
    return 0;
}
