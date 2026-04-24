#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef array<ll, 4> qii;
typedef vector<pii> vpii;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

ll n, m;
vpii Query;

vpii seg[404040];
ll g[101010];
vpii vec;

ll Find(ll x){return g[x]>0?Find(g[x]):x;}

void Union(ll a, ll b){
    a=Find(a); b=Find(b);
    if(a==b) vec.push_back({0, 0}), vec.push_back({0, 0});
    else{
        if(-g[a]<-g[b]) swap(a, b);
        vec.push_back({a, g[a]}); vec.push_back({b, g[b]});
        g[a]+=g[b]; g[b]=a;
    }
}

void Rollback(){
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
}

void update(ll N, ll s, ll e, ll l, ll r, pii q){
    if(r<s || e<l) return;
    else if(l<=s && e<=r) seg[N].push_back(q);
    else{
        ll m=s+e>>1;
        update(N<<1, s, m, l, r, q);
        update(N<<1|1, m+1, e, l, r, q);
    }
}

void solve(ll s, ll e, ll N){
    ll cnt=0;
    for(pii i : seg[N]) Union(i[0], i[1]), cnt++;
    if(s==e) cout << (Find(Query[s][0])==Find(Query[s][1])) << "\n";
    else{
        ll m=s+e>>1;
        solve(s, m, N<<1);
        solve(m+1, e, N<<1|1);
    }
    while(cnt--) Rollback();
}

int main(){
    fastio;

    cin >> n >> m;
    for(ll i=1; i<=n; i++) g[i]=-1;

    V<qii> ed, edges;
    map<pii, ll> lft; ll cnt=0;
    for(ll i=0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        if(b>c) swap(b, c);
        if(a==1) lft[{b, c}]=cnt;
        else if(a==2){
            ed.push_back({b, c, lft[{b, c}], cnt-1});
            lft.erase(lft.find({b, c}));
        }
        else Query.push_back({b, c}), cnt++;
    }
    for(pair<pii, ll> p : lft) ed.push_back({p.first[0], p.first[1], p.second, cnt-1});
    for(qii i : ed) if(i[2]<=i[3]) edges.push_back(i);
    for(qii i : edges) update(1, 0, cnt-1, i[2], i[3], {i[0], i[1]});

    solve(0, cnt-1, 1);

    return 0;
}
