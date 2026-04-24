#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define forf(i, s, e) for(ll i=s; i<e; i++)
const ll mod=1e9+7;

ll n;
V<set<ll>> cut;
ll pcnt;
V<vi> lnk;

void divide(ll s, ll e, ll bf){
    if(s+1==e) return;
    
    ll thp=pcnt++;
    if(bf!=-1){
        lnk[bf].push_back(thp);
        lnk[thp].push_back(bf);
    }
    
    ll p=*cut[e].begin();
    cut[s].erase(cut[s].find(p));
    cut[p].erase(cut[p].find(s));
    cut[e].erase(cut[e].find(p));
    cut[p].erase(cut[p].find(e));

    divide(s, p, thp);
    divide(p, e, thp);
}

ll ans;
ll dp(ll pnt, ll pre){
    ll ret=1;
    for(ll i : lnk[pnt]){
        if(i!=pre) ret=ret*(dp(i, pnt)+1)%mod;
    }
    ans=(ans+ret)%mod;
    return ret;
}

int main(){
    fastio;

    cin >> n;
    cut.resize(n);
    lnk.resize(n-2);

    forf(i, 0, n-1){
        cut[i].insert((i+1)%n);
        cut[(i+1)%n].insert(i);
    }
    forf(i, 0, n-3){
        ll a, b; cin >> a >> b;
        cut[a-1].insert(b-1);
        cut[b-1].insert(a-1);
    }

    divide(0, n-1, -1);

    dp(0, -1);
    cout << ans;

    return 0;
}
