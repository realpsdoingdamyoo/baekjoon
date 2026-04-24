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

typedef array<ll, 4> gld;

const ll X=13;
V<gld> seg(1<<X+1);

gld mrg(gld a, gld b){
    gld r;
    r[0]=max(a[0], a[2]+b[0]);
    r[1]=max(b[1], a[1]+b[2]);
    r[2]=a[2]+b[2];
    r[3]=max(max(a[3], b[3]), a[1]+b[0]);
    return r;
}

void update(ll p, ll x){
    p+=1<<X;
    forf(i, 0, 4) seg[p][i]+=x;
    p/=2;
    while(p){
        seg[p]=mrg(seg[p*2], seg[p*2+1]);
        p/=2;
    }
}

vi press(vi v){
    vi u=v; sortv(u);
    u.erase(unique(all(u)), u.end());
    forf(i, 0, v.size()){
        v[i]=lower_bound(all(u), v[i])-u.begin();
    }
    return v;
}

V<tii> comp(V<tii> v){
    ll n=v.size();
    forf(I, 0, 2){
        vi u(n);
        forf(i, 0, n) u[i]=v[i][I];
        u=press(u);
        forf(i, 0, n) v[i][I]=u[i];
    }
    return v;
}

int main(){
    //fastio;

    ll n; cin >> n;
    V<tii> v(n);
    forf(i, 0, n) forf(j, 0, 3) cin >> v[i][j];
    v=comp(v);

    V<V<tii>> sx(n);
    forf(i, 0, n){
        sx[v[i][0]].pb(v[i]);
        //cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << "\n";
    }

    ll ans=0;


    forf(i, 0, n){
        forf(j, 0, 1<<X+1) seg[j]={0, 0, 0, 0};


        forf(j, i, n){
            //for(tii t : sx[j]) cout << "[" << t[0] << " " << t[1] << " " << t[2] << "] ";
            for(tii t : sx[j]) update(t[1], t[2]);
            ans=max(ans, seg[1][3]);
            /*cout << seg[1][3] << " ";
            cout << " / ";*/
        }
        //cout << "\n";

    }
    cout << ans << "\n";

    return 0;
}
