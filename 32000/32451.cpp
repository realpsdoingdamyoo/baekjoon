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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

const ll X=19;
ll seg[1<<X+1];

void update(ll p, ll x){
    p+=1<<X;
    while(p){seg[p]+=x; p>>=1;}
}

ll sum(ll s, ll e){
    ll r=0; s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) r+=seg[s];
        if(~e&1) r+=seg[e];
        s=s+1>>1; e=e-1>>1;
    }
    return r;
}

ll findloc(ll k){
    ll s=0, e=(1<<X)-10;

    while(s<=e){
        ll m=s+e>>1;
        if(m-sum(0, m)<k) s=m+1;
        else e=m-1;
    }
    return s;
}

int main(){
    fastio;

    ll n; cin >> n;
    vpii v(n); vi u(n), ans(n), w(n);
    forf(i, 0, n) cin >> v[i][0];
    forf(i, 0, n) cin >> v[i][1];
    forf(i, 0, n*2) v[i/2][i%2]--;

    sortv(v);

    ll inv=0;
    forf(i, 0, n){
        u[v[i][1]]=sum(v[i][1], n);
        w[v[i][1]]=v[i][0];
        inv+=sum(v[i][1], n);
        update(v[i][1], 1);
    }

    if(inv%2){
        cout << "No";
        return 0;
    }
    else{
        cout << "Yes\n";
        inv>>=1;
    }

    vi mf(n);

    forf(i, 0, n){
        mf[i]=min(inv, u[i]);
        inv-=mf[i]; u[i]-=mf[i];
    }

    forf(i, 0, 1<<X+1) seg[i]=0;

    forf(i, 0, n){
        ll a=findloc(u[i]);
        ans[a]=i;
        update(a, 1);
    }

    forf(i, 0, n) cout << w[ans[i]]+1 << " "; cout << "\n";
    forf(i, 0, n) cout << ans[i]+1 << " ";

    return 0;
}
