#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<vi> vvi;
const ll mod=1e9+7, inf=2147483647;
#define V vector
#define pb push_back
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, e, s) for(ll i=e-1; i>=s; i--)

ll n, m, p;
vvi lnk;

pii dfs(ll pnt, ll pre, ll x){
    pii ret={0, 0};
    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        pii dr=dfs(i, pnt, x);
        ret={max(ret[0], dr[0]-1), ret[1]+dr[1]};
    }
    if(ret[0]==0 && pnt!=p){
        ret[0]=x;
        ret[1]++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> p; p--;
    lnk.resize(n);

    forf(i, 0, n-1){
        ll a, b; cin >>a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    ll s=1, e=n;

    while(s<=e){
        ll k=(s+e)>>1;
        if(dfs(p, -1, k)[1]<=m) e=k-1;
        else s=k+1;
    }

    if(s>n) cout << "-1";
    else cout << s;


    return 0;
}
