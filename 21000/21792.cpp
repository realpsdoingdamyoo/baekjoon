#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n;
vi lnk[200010];
bool centout[200010];
ll treedp[200010];
vpii trdps;
ll ans[200010];

pii piisum(pii a, pii b){
    vi pis;
    pis.pb(a[0]); pis.pb(b[0]);
    pis.pb(a[1]); pis.pb(b[1]);
    sortv(pis);
    return {pis[2], pis[3]};
}

ll dps(ll pnt, ll pre, ll typ, ll dst){
    ll ret=1;
    for(int i : lnk[pnt]){
        if(i!=pre && !centout[i]){
            ret+=dps(i, pnt, typ, dst+1);
        }
    }
    if(typ) trdps.pb({ret, dst});
    return treedp[pnt]=ret;
}

ll findcent(ll pnt, ll pre, ll treesz){
    for(ll i : lnk[pnt]){
        if(!centout[i] && i!=pre && treedp[i]>treesz/2)
            return findcent(i, pnt, treesz);
    }
    return pnt;
}

ll getcent(ll pnt){
    ll treesz=dps(pnt, -1, 0, 0);
    return findcent(pnt, -1, treesz);
}


void ptpt(ll cnt){
    //cout << "__" << cnt << "\n";
    ll subsz=dps(cnt, -1, 0, 0);
    vpii _p_offcl(subsz+2);

    for(int i : lnk[cnt]){
        if(centout[i]) continue;
        trdps.clear();
        ll ssz=dps(i, cnt, 1, 1);
        vi _p(ssz+1);
        for(pii p : trdps){
            _p[p[0]]=max(_p[p[0]], p[1]);
        }
        forb(j, ssz, 0){
            _p[j]=max(_p[j], _p[j+1]);
        }
        forf(j, 0, ssz+1){
            _p_offcl[j]=piisum(_p_offcl[j], {_p[j], 0});
        }
        //for(pii x : trdps) cout << "[" << x[0] << " " << x[1] << "]"; cout << "\n";
    }
    forf(i, 1, subsz+1){
        ans[i-1]=max(ans[i-1], _p_offcl[i][0]+_p_offcl[i][1]+1);
    }
}

void decomp(ll pnt){
    ll cent=getcent(pnt);
    ptpt(cent);
    centout[cent]=1;
    for(ll i : lnk[cent]) if(!centout[i]) decomp(i);
}

int main(){
    fastio;

    cin >> n;
    forf(i, 0, n-1){
        ll a, b;
        cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }
    decomp(0);

    forf(i, 0, n){
        if(i%2) cout << ans[i/2] << "\n";
        else cout << "1\n";
    }


    return 0;
}
