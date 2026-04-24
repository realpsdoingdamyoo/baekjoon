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

ll n, m, k;
vi seg, v;
V<pii> cpt;

ll F(ll len, vi u){
    vi L, R;
    ll Ll=-1, Rl=len, ret=0;
    for(ll i : u) L.pb(Ll+1), Ll+=i;
    reverse(all(u));
    for(ll i : u) R.pb(Rl-i), Rl-=i;
    reverse(all(R));

    forf(i, 0, u.size()){
        ret+=max(u[i]-abs(L[i]-R[i]), 0LL);
    }

    return ret;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k; k++;
    v.resize(n);
    cpt.resize(k);
    forf(i, 0, n) cin >> v[i];

    vi cut={0};
    forf(i, 1, k){
        ll a; cin >> a;
        cut.pb(a);
    }
    cut.pb(m+1);

    forf(i, 0, k){
        seg.pb(cut[i+1]-cut[i]-1);
    }

    ll id=-1;
    forf(i, 0, k){
        ll pt=0;
        while(id+1<n && pt+v[id+1]<=seg[i]){
            pt+=v[id+1]; id++;
        }

        cpt[i][0]=id;
    }

    id=n;
    forb(i, k, 0){
        ll pt=0;
        while(id-1>=0 && pt+v[id-1]<=seg[i]){
            pt+=v[id-1]; id--;
        }
        cpt[i][1]=id;
    }


    ll ans=0;
    forf(i, 0, k){
        ll s, e;
        if(i==0) s=0;
        else s=cpt[i-1][0]+1;

        if(i==k-1) e=n-1;
        else e=cpt[i+1][1]-1;

        vi u;
        forf(i, s, e+1) u.pb(v[i]);
        ans+=F(seg[i], u);
    }
    cout << ans;



    return 0;
}
