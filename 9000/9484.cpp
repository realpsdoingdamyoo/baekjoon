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
//const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

struct pnt{
    ll x, y;
    bool operator <(const pnt &p) const{
        return (pii){x, y}<(pii){p.x, p.y};
    }
    bool operator ==(const pnt &p) const{
        return (pii){x, y}==(pii){p.x, p.y};
    }
};

struct line{
    ll i, j, dx, dy;

    bool operator < (const line& l) const{
        ll le=dy*l.dx, ri=dx*l.dy;
        return (tii){le, i, j}<(tii){ri, l.i, l.j};
    }
    bool operator == (const line& l) const{
        return dy*l.dx==dx*l.dy;
    }
};

line L(ll i, ll j, pnt& pi, pnt& pj){
    line ret;
    ret.i=i; ret.j=j; ret.dx=pj.x-pi.x; ret.dy=pj.y-pi.y;
    return ret;
}

ll area(pnt& a, pnt& b, pnt& c){
    ll ret=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    return abs(ret);
}

ll n;
vi loc;
V<pnt> p;

bool solve(){
    cin >> n; if(n==0) return false;

    p.resize(n); loc.resize(n);
    for(pnt& i : p) cin >> i.x >> i.y;
    for(ll i=0; i<n; i++) loc[i]=i;
    sort(p.begin(), p.end());

    V<line> v;
    for(ll i=0; i<n; i++) for(ll j=i+1; j<n; j++)
        v.pb(L(i, j, p[i], p[j]));
    sortv(v);

    ll mn=inf, mx=-inf;
    for(ll i=0, j=0; i<v.size(); i=j){
        while(j<v.size() && v[i]==v[j]) j++;

        for(ll k=i; k<j; k++){
            ll pi=v[k].i, pj=v[k].j;
            swap(loc[pi], loc[pj]);
            swap(p[loc[pi]], p[loc[pj]]);
            if(loc[pi]>loc[pj]) swap(pi, pj);

            if(loc[pi]>0){
                mn=min(mn, area(p[loc[pi]], p[loc[pj]], p[loc[pi]-1]));
                mx=max(mx, area(p[loc[pi]], p[loc[pj]], p[0]));
            }
            if(loc[pj]<n-1){
                mn=min(mn, area(p[loc[pi]], p[loc[pj]], p[loc[pj]+1]));
                mx=max(mx, area(p[loc[pi]], p[loc[pj]], p[n-1]));
            }
        }
    }

    cout << mn/2 << "." << mn*5%10 << " ";
    cout << mx/2 << "." << mx*5%10 << "\n";

    return true;
}

int main(){
    fastio;

    while(solve()){}

    return 0;
}
