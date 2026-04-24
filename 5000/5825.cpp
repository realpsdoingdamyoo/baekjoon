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

ll n, ans;
vpii lnk[303030];
ll trsz[303030];
bool centout[303030];

ll trsz_dp(ll pnt, ll pre){
    trsz[pnt]=1;
    for(pii i : lnk[pnt]) if(i[0]!=pre && !centout[i[0]]) trsz[pnt]+=trsz_dp(i[0], pnt);
    return trsz[pnt];
}

ll getcent(ll pnt, ll pre, ll sz){
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]] && trsz[i[0]]>sz/2)
            return getcent(i[0], pnt, sz);
    return pnt;
}

ll _mp[606060], _mp_[606060];
vi newp, newp_;

void dfs_1(ll pnt, ll pre, ll now, pii pst){
    if(pst[0]<=now && now<=pst[1]) newp.pb(now);
    else newp_.pb(now);
    pst[0]=min(pst[0], now);
    pst[1]=max(pst[1], now);
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]])
            dfs_1(i[0], pnt, now+i[1], pst);
}

void dfs_2(ll pnt, ll pre, ll now, bool pst){
    if(now==0 && pst) ans++;
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]])
            dfs_2(i[0], pnt, now+i[1], pst||(now==0));
}

void centing(ll cent, ll sz){
    forf(i, 303030-sz, 303030+sz+1) _mp[i]=0;
    forf(i, 303030-sz, 303030+sz+1) _mp_[i]=0;
    for(pii i : lnk[cent]){
        if(!centout[i[0]]){
            newp.clear(); newp_.clear();
            dfs_1(i[0], cent, i[1], {0, 0});
            for(ll _p : newp)
                ans+=_mp_[303030-_p];
            for(ll _p : newp_)
                ans+=_mp[303030-_p];
            for(ll _p : newp) _mp[303030+_p]++;
            for(ll _p : newp) _mp_[303030+_p]++;
            for(ll _p : newp_) _mp_[303030+_p]++;
            dfs_2(i[0], cent, i[1], 0);
        }
    }
}

void decomp(ll pnt){
    ll TSZ=trsz_dp(pnt, 0);
    ll cent=getcent(pnt, -1, TSZ);
    centing(cent, TSZ);
    centout[cent]=1;
    for(pii i : lnk[cent]) if(!centout[i[0]]) decomp(i[0]);
}

int main(){
    fastio;

    cin >> n;
    forf(i, 1, n){
        ll a, b, c; cin >> a >> b >> c;
        c-=!c;
        lnk[a].pb({b, c}); lnk[b].pb({a, c});
    }
    decomp(1);
    cout << ans;

    return 0;
}
