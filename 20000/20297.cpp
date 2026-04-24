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
vi num;
vvi lnk;
vi centout;
vi stsize;

ll stset(ll pnt, ll pre){
    ll stsz=1;
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i])
            stsz+=stset(i, pnt);
    }
    stsize[pnt]=stsz;
    return stsz;
}

ll centfind(ll pnt, ll pre, ll subsize){
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i] && stsize[i]>=subsize/2)
            return centfind(i, pnt, subsize);
    }
    return pnt;
}

map<ll, ll> distmap;

ll dstfind(ll pnt, ll pre, ll dis, ll cnum){
    ll bst=inf;
    if(num[pnt]==cnum || distmap[num[pnt]]){
        bst=distmap[num[pnt]]+dis;
    }

    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i]){
            bst=min(bst, dstfind(i, pnt, dis+1, cnum));
        }
    }
    return bst;
}

ll best_cent(ll cent){
    ll bestway=inf;
    distmap.clear();

    for(ll i : lnk[cent]){
        bestway=min(bestway, dstfind(i, cent, 1, num[cent]));
    }
    return bestway;
}

ll decomp(ll pnt){
    ll best_path=inf;
    ll subsize=stset(pnt, -1);
    ll cent=centfind(pnt, -1, subsize);
    best_path=min(best_path, best_cent(cent));
    centout[cent]=1;
    for(ll i : lnk[cent]){
        if(!centout[i]) best_path=min(best_path, decomp(i));
    }
    return best_path;
}

int main(){
    fastio;

    cin >> n;
    num.resize(n); lnk.resize(n);
    centout.resize(n); stsize.resize(n);

    forf(i, 0, n) cin >> num[i];
    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    cout << decomp(0);


    return 0;
}
