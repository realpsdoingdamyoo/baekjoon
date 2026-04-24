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

ll n;
vi num;
vvi lnk;
vi centout;
vi stsize;
ll ans;
string st;

ll stset(ll pnt, ll pre){
    ll stsz=1;
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i])
            stsz+=stset(i, pnt);
    }
    stsize[pnt]=stsz;
    return stsz;
}

ll centfind(ll pnt, ll pre, ll subsize){
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i] && stsize[i]>=subsize/2)
            return centfind(i, pnt, subsize);
    }
    return pnt;
}

map<tii, ll> ucpc;
V<tii> triple;

tii rvsucp(tii ucp){
    ll u=max(max(ucp[0], (ucp[1]+1)/2), ucp[2]);
    forf(i, 0, 3) ucp[i]=u-ucp[i]; ucp[1]+=u;
    return ucp;
}

tii ucpdown(tii ucp){
    ll m=min(min(ucp[0], ucp[1]/2), ucp[2]);
    ucp[0]-=m; ucp[1]-=m*2; ucp[2]-=m;
    return ucp;
}

ll ucpcdfs(ll pnt, ll pre, tii ucp, tii ucpp){
    ll ret=0;
    if(st[pnt]=='U'){ucp[0]++; ucpp[0]++;}
    if(st[pnt]=='C'){ucp[1]++; ucpp[1]++;}
    if(st[pnt]=='P'){ucp[2]++; ucpp[2]++;}
    ucp=ucpdown(ucp);

    ret+=ucpc[rvsucp(ucpp)];
    //cout << ucp[0] << " " <<ucp[1] << " " <<ucp[2] << "_";
    //cout << ucpp[0] << " " <<ucpp[1] << " " <<ucpp[2] << "_";
    tii ucpf=rvsucp(ucpp);
    //cout << ucpf[0] << " " <<ucpf[1] << " " <<ucpf[2] << "_" << ucpc[rvsucp(ucpp)] << "\n";
    triple.pb(ucp);

    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i])
            ret+=ucpcdfs(i, pnt, ucp, ucpp);
    }
    return ret;
}

ll centpick_(ll pnt){
    ucpc.clear();
    tii ucp={}, ucpp={};
    if(st[pnt]=='U') ucpp[0]++;
    if(st[pnt]=='C') ucpp[1]++;
    if(st[pnt]=='P') ucpp[2]++;
    ucpc[ucp]++;

    ll ret=0;
    for(ll i : lnk[pnt]){
        if(!centout[i]){
            triple.clear();
            ret+=ucpcdfs(i, pnt, ucp, ucpp);
            for(tii j : triple) ucpc[j]++;
        }
    }
    return ret;
}

ll decomp(ll pnt, ll par){
    ll best_path=inf;
    ll subsize=stset(pnt, n);
    ll cent=centfind(pnt, n, subsize);
    ll ret=0;
    //cout << cent+1 <<"\n";
    ret+=centpick_(cent);
    centout[cent]=1;
    for(ll i : lnk[cent]){
        triple.clear();
        if(!centout[i]) ret+=decomp(i, cent);
    }
    return ret;
}

int main(){
    fastio;

    cin >> n;
    num.resize(n); lnk.resize(n);
    centout.resize(n); stsize.resize(n);

    cin >> st;

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    cout << decomp(0, n);




    return 0;
}
