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


ll n, r;
vvi lnk;
vi v;


struct cmp {
	bool operator()(tii a, tii b){
        return a[2]*b[1]<=b[2]*a[1];
    }
};
typedef PQ<tii, V<tii>, cmp> pQ;

pQ pq, dpq;
tii mrg(tii a, tii b){
    return {a[0]+b[0]+b[2]*a[1], a[1]+b[1], a[2]+b[2]};
}

pQ dfs(ll pnt, ll pre){
    pQ res;

    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        pQ tmp=dfs(i, pnt);
        if(tmp.size()>res.size()) swap(tmp, res);
        while(tmp.size()){
            res.push(tmp.top());
            tmp.pop();
        }
    }

    tii cur={v[pnt], 1, v[pnt]};

    while(res.size() && cur[2]*res.top()[1]<=res.top()[2]*cur[1]){
        cur=mrg(cur, res.top()); res.pop();
    }
    res.push(cur);
    return res;
}

int main(){
    fastio;

    cin >> n >> r; r--;
    lnk.resize(n);
    v.resize(n);
    forf(i, 0, n) v[i]=-(i+1);

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    pQ res=dfs(r, -1);
    tii ans=res.top(); res.pop();
    while(res.size()){
        ans=mrg(ans, res.top());
        res.pop();
    }
    cout << -ans[0];

    return 0;
}
