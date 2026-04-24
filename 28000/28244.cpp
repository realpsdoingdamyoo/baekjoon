#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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
vpii lnk[202020];
bool centout[202020];
ll trsz[202020];

ll trdp(ll pnt, ll pre){
    trsz[pnt]=1;
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]])
            trsz[pnt]+=trdp(i[0], pnt);
    return trsz[pnt];
}

ll getcent(ll pnt, ll pre, ll sz){
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]] && trsz[i[0]]>sz/2)
            return getcent(i[0], pnt, sz);
    return pnt;
}

ll s, c;
ll mp[202020], cnt[202020];
PQ<tii> pq;

void dfs(ll pnt, ll pre, ll x, ll mx, ll dst){
    s+=dst; c++; mp[x]+=dst; cnt[x]++;
    pq.push({mx, dst, x});
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]])
            dfs(i[0], pnt, x, max(mx, i[1]), dst+i[1]);
}

ll centing(ll cent){
    s=0; c=0;
    while(pq.size()) pq.pop();

    c++; cnt[cent]=1;
    pq.push({0, 0, cent});

    for(pii i : lnk[cent]){
        if(!centout[i[0]]){
            mp[i[0]]=0; cnt[i[0]]=0;
            dfs(i[0], cent, i[0], i[1], i[1]);
        }
    }

    ll ret=0;
    while(pq.size()){
        tii tp=pq.top(); pq.pop();
        ret+=(s-mp[tp[2]])%mod*tp[0]%mod+tp[0]*(tp[1]%mod)%mod*(c-cnt[tp[2]])%mod;
        s-=tp[1]; mp[tp[2]]-=tp[1];
        c--; cnt[tp[2]]--;
    }
    return ret%mod;
}

ll decomp(ll x, ll k){
    ll sz=trdp(x, -1);
    ll cent=getcent(x, -1, sz);
    ll ret=centing(cent);
    centout[cent]=true;
    for(pii i : lnk[cent])
        if(!centout[i[0]]) ret+=decomp(i[0], k+1);
    return ret%mod;
}

int main(){
    fastio;

    cin >> n;
    forf(i, 0, n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        lnk[a-1].pb({b-1, c});
        lnk[b-1].pb({a-1, c});
    }

    cout << decomp(0, 0);

    return 0;
}
