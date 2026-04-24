#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, m;
string s[3003];
array<int, 3> v[3003][3003];

signed main(){
    fastio;

    cin >> n >> m;
    string p="RGW";
    for(int i=0; i<n; i++) cin >> s[i];

    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        if(0<i && i<n-1) v[i][j][1]=(s[i-1][j]=='R' && s[i][j]=='G' && s[i+1][j]=='W');
        if(0<j && j<m-1) v[i][j][2]=(s[i][j-1]=='R' && s[i][j]=='G' && s[i][j+1]=='W');
    }

    int ret=0;
    for(int I=0; I<=n+m-2; I++) for(int i=max(0LL, I-m+1); i<=min(n-1, I); i++){
        int j=I-i;

        if(i!=max(0LL, I-m+1)){
            array<int, 3>& c=v[i][j], p=v[i-1][j+1];
            c[0]+=max(p[0], max(p[1], p[2]));
            c[1]+=max(p[0], p[1]);
            c[2]+=max(p[0], p[2]);
        }

        if(i==min(n-1, I)) ret+=max(v[i][j][0], max(v[i][j][1], v[i][j][2]));
    }
    cout << ret;

    return 0;
}
