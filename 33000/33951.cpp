#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int dpa[2020][2020];
int dpb[2020][2020];

signed main(){
    fastio;

    int n, m, p, k; cin >> n >> m >> k; p=n+m-1;
    vector<string> s(n);
    for(string& i : s) cin >> i;

    dpa[0][0]=(s[0][0]=='A');
    dpb[0][0]=(s[0][0]=='B');

    for(int i=1; i<n; i++) dpa[i][0]=dpa[i-1][0]+(s[i][0]=='A');
    for(int i=1; i<n; i++) dpb[i][0]=dpb[i-1][0]+(s[i][0]=='B');

    for(int i=1; i<m; i++) dpa[0][i]=dpa[0][i-1]+(s[0][i]=='A');
    for(int i=1; i<m; i++) dpb[0][i]=dpb[0][i-1]+(s[0][i]=='B');

    for(int i=1; i<n; i++) for(int j=1; j<m; j++){
        dpa[i][j]=max(dpa[i-1][j], dpa[i][j-1])+(s[i][j]=='A');
        dpb[i][j]=max(dpb[i-1][j], dpb[i][j-1])+(s[i][j]=='B');
    }

    int mxa=dpa[n-1][m-1], mxb=dpb[n-1][m-1];

    for(int i=0; i<k; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a==b){
            if(a*p==c) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            int A=(c-p*b)/(a-b), B=(c-p*a)/(b-a);
            if(A<0 || B<0 || abs(c-p*b)%abs(a-b)) cout << "NO\n";
            else if(A>mxa || B>mxb) cout << "NO\n";
            else cout <<"YES\n";
        }
    }

    return 0;
}
