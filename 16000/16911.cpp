#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 4> qii;
typedef vector<pii> vpii;
#define V vector
#define P push_back
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

ll n, m, g[101010];
vpii Query, vec;

ll Find(ll x){return g[x]>0?Find(g[x]):x;}

void Union(ll a, ll b){
    a=Find(a); b=Find(b);
    if(a==b) vec.P({0, 0}), vec.P({0, 0});
    else{
        if(-g[a]<-g[b]) swap(a, b);
        vec.P({a, g[a]}); vec.P({b, g[b]});
        g[a]+=g[b]; g[b]=a;
    }
}

void Rollback(){
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
}

void solve(ll s, ll e, V<qii> edge){
    if(s==e){
        for(qii i : edge) Union(i[0], i[1]);
        cout << (Find(Query[s][0])==Find(Query[s][1])) << "\n";
        for(qii i : edge) Rollback();
        return;
    }

    ll m=s+e>>1, cnt=0;
    V<qii> le, re;
    for(qii i : edge){
        if(i[2]<=s && i[3]>=e) Union(i[0], i[1]), cnt++;
        else{
            if(max(i[2], s)<=min(i[3], m)) le.P(i);
            if(max(i[2], m+1)<=min(i[3], e)) re.P(i);
        }
    }
    solve(s, m, le); solve(m+1, e, re);
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
            ed.P({b, c, lft[{b, c}], cnt-1});
            lft.erase(lft.find({b, c}));
        }
        else Query.P({b, c}), cnt++;
    }
    for(pair<pii, ll> p : lft) ed.P({p.first[0], p.first[1], p.second, cnt-1});
    for(qii i : ed) if(i[2]<=i[3]) edges.P(i);

    solve(0, cnt-1, edges);

    return 0;
}
