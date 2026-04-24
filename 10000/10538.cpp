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


ll hp, wp, hm, wm, s;
V<S> sp, bp;



int main(){
    fastio;

    cin >> hp >> wp >> hm >> wm;
    sp.resize(hp); bp.resize(hm);
    forf(i, 0, hp) cin >> sp[i];
    forf(i, 0, hm) cin >> bp[i];

    ll Hs=0;
    forf(i, 0, hp*wp) Hs=(Hs*2+(sp[i/wp][i%wp]=='o'))%mod;

    vvi Hr(hm);
    ll pw=1;
    forf(i, 0, wp) pw=pw*2%mod;

    forf(i, 0, hm){
        ll H=0;
        forf(j, 0, wp){
            H=(2*H+(bp[i][j]=='o'))%mod;
        }
        Hr[i].pb(H);

        forf(j, wp, wm){
            H=(2*H+(bp[i][j]=='o')-pw*(bp[i][j-wp]=='o')+mod)%mod;
            Hr[i].pb(H);
        }
    }


    vvi Hc(hm-hp+1);
    forf(i, 0, hm-hp+1) Hc[i].resize(wm-wp+1);
    ll ppw=1;
    forf(i, 0, hp) ppw=ppw*pw%mod;

    forf(j, 0, wm-wp+1){
        ll H=0;
        forf(i, 0, hp) H=(pw*H+Hr[i][j])%mod;
        Hc[0][j]=H;

        forf(i, hp, hm){
            H=(pw*H+Hr[i][j]-ppw*Hr[i-hp][j]%mod+mod)%mod;
            Hc[i-hp+1][j]=H;
        }
    }

    forf(i, 0, hm-hp+1) forf(j, 0, wm-wp+1) s+=(Hc[i][j]==Hs);
    cout << s << "\n";

    return 0;
}
