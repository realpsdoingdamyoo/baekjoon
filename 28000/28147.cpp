#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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

typedef array<ll, 4> qii;

ll n;
vvi lnk;
V<double> T, P, X;


struct poi{
    lf x, t, p;
    ll id;
};

struct cmp {
	bool operator()(poi a, poi b){
        return a.x>=b.x;
    }
};
bool CMP(poi a, poi b){
    return a.x>=b.x;
}
typedef PQ<poi, V<poi>, cmp> pQ;

pQ pq;
poi mrg(poi a, poi b){
    return {(a.t+b.t*a.p)/(1-a.p*b.p), a.t+b.t*a.p, a.p*b.p, a.id};
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

    poi cur={T[pnt]/(1-P[pnt]), T[pnt], P[pnt], pnt};

    while(res.size() && CMP(cur, res.top())){
        cur=mrg(cur, res.top());
        res.pop();
    }
    if(pnt) res.push(cur);
    X[pnt]=cur.x;
    T[pnt]=cur.t;
    P[pnt]=cur.p;
    return res;
}

int main(){
    fastio;

    cin >> n; n++;
    lnk.resize(n);
    T.resize(n);
    P.resize(n);
    X.resize(n);
    forf(i, 1, n){
        ll b; double a, p;
        cin >> a >> p >> b;
        T[i]=a;
        P[i]=p;
        lnk[b].pb(i);
    }

    pQ res=dfs(0, -1);
    poi ans={0, 0, 1, 0};
    while(res.size()){
        ans=mrg(ans, res.top());
        res.pop();
    }
    cout.precision(10);
    PQ<pair<lf, ll>> pqr; pqr.push({0, 0});
    while(pqr.size()){
        ll tp=pqr.top().second; pqr.pop();
        if(tp) cout << tp << "\n";
        for(ll i : lnk[tp]) pqr.push({-X[i], i});
    }

    return 0;
}
