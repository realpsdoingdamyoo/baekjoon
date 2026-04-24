#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef array<int, 2> pii;
typedef array<int, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e7+7, MOD=998244353, inf=2147483647;
const int BI=69696969696969;

int n, p, f;
pii v[404040];
pii sp[404040];
int dp[404040];

signed main(){
    fastio;

    cin >> p >> f; n=p+f;
    for(int i=0; i<404040; i++) dp[i]=BI; dp[n]=0;
    for(int i=0, j; i<p; i++){cin >> j; v[i]={j, 0};}
    for(int i=0, j; i<f; i++){cin >> j; v[i+p]={j, 1};}
    sort(v, v+n);

    int cn[2]={0, 0};
    for(int i=n-1; i>=0; i--){
        int j=i+1, ret=0;
        while(j<n && v[j][1]==v[i][1]){
            ret+=sp[j][1];
            j=sp[j][0];
        }
        sp[i]={j+1, v[j][0]-v[i][0]+ret};

        dp[i]=dp[j+1]+sp[i][1];
        if(v[i][1]==0) dp[i]=min(dp[i], dp[i+1]);
    }

    cout << dp[0];


    return 0;
}
