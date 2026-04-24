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

ll n, m, c, cnt, A;
vi clr, ett;
vpii se, vert;
vvi lnk;

bool cmp(pii a, pii b){return a[1]<b[1];}

void dfs(ll pnt, ll pre){
    ett[cnt]=pnt;
    se[pnt][0]=cnt++;
    for(ll i : lnk[pnt])
        if(i!=pre) dfs(i, pnt);
    se[pnt][1]=cnt-1;
}

const ll X=18;
ll seg[1<<X+1];

void update(ll p, ll x){
    p+=1<<X;
    while(p){
        seg[p]+=x;
        p>>=1;
    }
}

ll sum(ll s, ll e){
    s+=1<<X; e+=1<<X;
    ll r=0;
    while(s<=e){
        if(s&1) r+=seg[s]; s=(s+1)/2;
        if(~e&1) r+=seg[e]; e=(e-1)/2;
    }
    return r;
}

int main(){
    fastio;

    cin >> n >> m >> c;
    lnk.resize(n);
    ett.resize(n);
    se.resize(n);
    clr.resize(n);
    forf(i, 0, n){
        cin >> clr[i];
        vert.pb({clr[i], i});
    } sortv(vert);

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }
    dfs(0, -1);

    vpii Q(m);
    forf(i, 0, m){
        cin >> Q[i][0] >> Q[i][1];
        Q[i][0]--;
    }
    sortc(Q, cmp);

    ll ind=0;
    for(pii i : Q){
        while(ind<n && vert[ind][0]<=i[1]){
            update(se[vert[ind][1]][0], 1);
            ind++;
        }

        A+=sum(se[i[0]][0], se[i[0]][1]);
    }
    cout << A%mod << "\n";

    return 0;
}
