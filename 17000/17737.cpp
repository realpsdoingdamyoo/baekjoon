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

bool cmpy(pii a, pii b){
    return a[1]<b[1];
}

void update(vi& seg, ll X, ll p, ll x){
    p+=1<<X;
    seg[p]=x; p/=2;
    while(p){
        seg[p]=seg[p*2]+seg[p*2+1];
        p/=2;
    }
}

ll sum(vi& seg, ll X, ll s, ll e){
    s+=1<<X; e+=1<<X;
    ll ret=0;
    while(s<=e){
        if(s%2==1) ret+=seg[s]; s=(s+1)/2;
        if(e%2==0) ret+=seg[e]; e=(e-1)/2;
    }
    return ret;
}

ll dnc(vpii v){
    if(v.size()==1) return 0;

    ll n=v.size();
    vpii d, u;
    forf(i, 0, n/2) d.pb(v[i]);
    forf(i, n/2, n) u.pb(v[i]);
    ll ret=dnc(d)+dnc(u);

    ll m=v[n/2-1][0];

    sortc(v, cmpy);
    vpii ds, us;
    map<pii, ll> ord;

    ll X=1;
    while((1<<X)<n) X++;

    vi seg(1<<X+1);

    forf(i, 0, n){
        ord[v[i]]=i;
        if(v[i][0]<=m){
            while(ds.size() && ds.back()[0]<v[i][0]){
                update(seg, X, ord[ds.back()], 0);
                ds.pop_back();
            }
            ds.pb(v[i]);
            update(seg, X, i, 1);
        }
        else{
            while(us.size() && us.back()[0]>v[i][0]) us.pop_back();
            ll vip=0;
            if(us.size()==0) vip=sum(seg, X, 0, i);
            else vip=sum(seg, X, ord[us.back()], i);
            us.pb(v[i]); ret+=vip;
        }
    }
    return ret;
}

int main(){
    fastio;

    ll n; cin >> n;
    vpii v(n);
    forf(i, 0, n) cin >> v[i][0] >> v[i][1];
    sortv(v);

    cout << dnc(v);

    return 0;
}
