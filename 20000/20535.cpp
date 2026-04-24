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
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, q, cnt;
vi lnk[505050];
ll ett[1010101];
ll in[505050];
ll dep[505050];

void ettdfs(ll p, ll depth){
    ett[++cnt]=p; in[p]=cnt;
    dep[p]=depth;
    for(ll i : lnk[p]){
        ettdfs(i, depth+1);
        ett[++cnt]=p;
    }
}


const ll X=20;
ll seg[1<<X+1];
void seginit(){
    forf(i, 1, 2*n){
        seg[i+(1<<X)]=dep[ett[i]];
    }
    forb(i, X, 0)
        forf(j, 1<<i, 1<<i+1)
            seg[j]=min(seg[j*2], seg[j*2+1]);
}

ll segmin(ll s, ll e){
    ll r=inf; s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s%2==1) r=min(r, seg[s]); s=(s+1)/2;
        if(e%2==0) r=min(r, seg[e]); e=(e-1)/2;
    }
    return r;
}

vi qv;
vi hv;
ll x;

vpii qseg;

void qseginit(){
    x=0;
    while((1<<x)<hv.size()) x++;
    qseg.resize(1<<x+1);

    forf(i, 0, hv.size()){
        qseg[i+(1<<x)]={hv[i], i};
    }
    forb(i, x, 0)
        forf(j, 1<<i, 1<<i+1)
            qseg[j]=min(qseg[j*2], qseg[j*2+1]);
}

pii qsegmin(ll s, ll e){
    pii r={inf, inf}; s+=1<<x; e+=1<<x;
    while(s<=e){
        if(s%2==1) r=min(r, qseg[s]); s=(s+1)/2;
        if(e%2==0) r=min(r, qseg[e]); e=(e-1)/2;
    }
    return r;
}

ll cutting(ll s, ll e){
    if(s>e) return 0;
    if(s==e) return qsegmin(s, e)[0];
    pii mini=qsegmin(s, e);
    ll m=mini[1], ret=0;
    ret=mini[0]*(e-m+1)*(m-s+1);
    ret+=cutting(s, m-1)+cutting(m+1, e);
    return ret;
}

void Q(){
    ll s; cin >> s;
    qv.resize(s); hv.clear();
    forf(i, 0, s) cin >> qv[i];
    forf(i, 0, s) qv[i]=in[qv[i]];
    sortv(qv);
    //forf(i, 0, s) cout << qv[i] << " "; cout << "\n";
    forf(i, 0, s-1) hv.pb(segmin(qv[i], qv[i+1]));
    //forf(i, 0, s-1) cout << hv[i] << " "; cout << "\n";

    qseginit();

    cout << cutting(0, s-2) << "\n";
}

int main(){
    fastio;

    cin >> n >> q;
    forf(i, 2, n+1){
        ll a; cin >> a;
        lnk[a].pb(i);
    }

    ettdfs(1, 0);
    seginit();


    /*forf(i, 0, 2*n+1) cout << ett[i] << " ";
    cout << "\n\n";*/

    while(q--) Q();

    return 0;
}
