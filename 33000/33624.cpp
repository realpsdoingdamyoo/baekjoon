#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<vi> vvi;
const ll mod=1e9+7;
#define V vector
#define pb push_back
#define forf(i, s, e) for(ll i=s; i<e; i++)

vvi lnk;
V<pii> dp;
vi sz;
// 일로 갖다놓으면 이기는거 0, 지는거 1

void dfs(ll pnt, ll pre){
    if(lnk[pnt].size()==1 && lnk[pnt][0]==pre){
        dp[pnt]={1, 0};
        sz[pnt]=1;
        return;
    }

    dp[pnt]={1, 1};
    sz[pnt]=1;

    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        dfs(i, pnt);
        dp[pnt][0]=dp[pnt][0]*dp[i][1]%mod;
        sz[pnt]=sz[pnt]*sz[i]*2%mod;
    }
    dp[pnt][1]=(sz[pnt]-dp[pnt][0]+mod)%mod;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, r; cin >> n >> r; r--;
    lnk.resize(n);
    dp.resize(n);
    sz.resize(n);

    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    dfs(r, -1);

    cout << dp[r][1] << "\n";

    return 0;
}
