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

typedef array<ll, 4> qii;

const ll X=12;
struct goldseg{
    qii seg[1<<X+1];

    qii merg(ll a, ll b){
        qii l=seg[a], r=seg[b];

        qii ret;
        ret[0]=max(max(l[0], r[0]), l[2]+r[1]);
        ret[1]=max(l[3]+r[1], l[1]);
        ret[2]=max(r[3]+l[2], r[2]);
        ret[3]=l[3]+r[3];

        return ret;
    }

    void update(ll p, ll x){
        p+=1<<X;
        seg[p]={max(0LL, x), max(0LL, x), max(0LL, x), x};
        p>>=1;

        while(p){
            seg[p]=merg(p<<1, p<<1|1);
            p>>=1;
        }
    }

    ll query(){
        return seg[1][0];
    }

} seg;

struct pnt{
    ll x, y, c;
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

ll n;
vi loc;
V<pnt> p;

int main(){
    fastio;

    cin >> n;

    p.resize(n); loc.resize(n);
    for(pnt& i : p){
        cin >> i.x >> i.y >> i.c;
    }
    for(ll i=0; i<n; i++) loc[i]=i;
    sort(p.begin(), p.end());

    V<line> v;
    for(ll i=0; i<n; i++) for(ll j=i+1; j<n; j++)
        v.pb(L(i, j, p[i], p[j]));
    sortv(v);

    for(ll i=0; i<n; i++) seg.update(i, p[i].c);

    ll mn=inf, mx=-inf, ret=seg.query();
    for(ll i=0, j=0; i<v.size(); i=j){
        while(j<v.size() && v[i]==v[j]) j++;

        for(ll k=i; k<j; k++){
            ll pi=v[k].i, pj=v[k].j;
            swap(loc[pi], loc[pj]);
            swap(p[loc[pi]], p[loc[pj]]);
            if(loc[pi]>loc[pj]) swap(pi, pj);

            seg.update(loc[pi], p[loc[pi]].c);
            seg.update(loc[pj], p[loc[pj]].c);
        }
        ret=max(ret, seg.query());
    }

    cout << ret;

    return 0;
}
