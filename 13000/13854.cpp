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

ll isp[101010];

void isp_init(){
    forf(i, 2, 101010) isp[i]=1;
    forf(i, 2, 350){
        if(isp[i]==0) continue;
        for(ll j=i*i; j<101010; j+=i) isp[j]=0;
    }
}


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
        if(i!=pre && !centout[i] && stsize[i]>subsize/2)
            return centfind(i, pnt, subsize);
    }
    return pnt;
}



const double PI = acos(-1);
typedef complex<double> cpx;
void FFT(vector<cpx> &v, bool inv) {
    ll S = v.size();

    for(ll i=1, j=0; i<S; i++) {
        ll bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(ll k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for(ll i=0; i<S; i+=k*2) {
            cpx z(1, 0);

            for(ll j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }
    if(inv) for(ll i=0; i<S; i++) v[i] /= S;
}
vi mul(vi &v, vi &u) {
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    ll S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);

    for(ll i=0; i<S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vi w(S);
    for(ll i=0; i<S; i++) w[i] = round(vc[i].real());

    return w;
}


void sumvec(vi& a, vi& b){
    a.resize(max(a.size(), b.size()));
    b.resize(max(a.size(), b.size()));
    forf(i, 0, a.size()) a[i]+=b[i];
}

void dfs(ll pnt, ll pre, ll dep, vi& sv){
    while(dep>=sv.size()) sv.pb(0);
    sv[dep]++;
    for(ll i : lnk[pnt])
        if(i!=pre && !centout[i])
            dfs(i, pnt, dep+1, sv);
}

ll centpick_(ll pnt){
    vi sumv, onev, sqv; sumv.pb(1);
    for(ll i : lnk[pnt]){
        if(centout[i]) continue;
        onev.clear();
        dfs(i, pnt, 1, onev);
        sumvec(sumv, onev);
        onev=mul(onev, onev);
        sumvec(sqv, onev);
    }
    sumv=mul(sumv, sumv);
    forf(i, 0, sqv.size()) sqv[i]*=-1;
    sumvec(sumv, sqv);
    ll ret=0;
    forf(i, 0, sumv.size()) ret+=sumv[i]*isp[i]/2;
    return ret;
}

ll decomp(ll pnt, ll par){
    ll best_path=inf;
    ll subsize=stset(pnt, n);
    ll cent=centfind(pnt, n, subsize);
    ll ret=0;
    ret+=centpick_(cent);
    centout[cent]=1;
    for(ll i : lnk[cent]){
        if(!centout[i]) ret+=decomp(i, cent);
    }
    return ret;
}

int main(){
    fastio;
    isp_init();

    cin >> n;
    num.resize(n); lnk.resize(n);
    centout.resize(n); stsize.resize(n);


    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }
    cout.precision(10);
    cout << (lf)decomp(0, n)*2/n/(n-1);

    return 0;
}
