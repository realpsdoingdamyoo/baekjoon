#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;
const double pi=acos(-1);

int n;
string s;
int h[3030][3030];
int ans[3030];

signed main(){
    fastio;

    cin >> n >> s;
    for(int i=0; i<n; i++){
        int H=0;
        for(int j=i; j<n; j++){
            H=(H*101+s[j])%MOD;
            h[i][j]=H;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int d=j-i+1, l=i, r=j;
            for(int k=0; k<=n; k++){
                if(l<0 || r>=n) break;
                if(h[l][l+d-1]==h[r-d+1][r]){
                    ans[d]++; l-=d; r+=d;
                }
                else break;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int d=j-i+1, l=i, r=j+d;
            for(int k=0; k<=n; k++){
                if(l<0 || r>=n) break;
                if(h[l][l+d-1]==h[r-d+1][r]){
                    ans[d]++; l-=d; r+=d;
                }
                else break;
            }
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i] << "\n";

    return 0;
}
