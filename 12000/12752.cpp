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

ll n, k, m;
V<vpii> lnk;

vi imp;
unordered_map<ll, vi> DST1;
unordered_map<ll, unordered_map<ll, vi>> DST2;

vi DIJK1(ll st){
    vi dst(n);
    forf(i, 0, n) dst[i]=inf*910191;
    dst[st]=0;

    PQ<pii> pq; pq.push({0, st});

    while(pq.size()){
        ll pd=-pq.top()[0];
        ll pn=pq.top()[1];
        pq.pop();

        if(dst[pn]<pd) continue;

        for(pii i : lnk[pn]){
            ll nn=i[0];
            ll nd=pd+i[1];
            if(nd<dst[nn]){
                dst[nn]=nd;
                pq.push({-nd, nn});
            }
        }
    }
    return dst;
}

vi DIJK2(ll st1, ll st2){
    vi dst(n); PQ<pii> pq;
    forf(i, 0, n) dst[i]=DST1[st1][i]+DST1[st2][i];
    forf(i, 0, n) pq.push({-dst[i], i});

    while(pq.size()){
        ll pd=-pq.top()[0];
        ll pn=pq.top()[1];
        pq.pop();

        if(dst[pn]<pd) continue;

        for(pii i : lnk[pn]){
            ll nn=i[0];
            ll nd=pd+i[1];
            if(nd<dst[nn]){
                dst[nn]=nd;
                pq.push({-nd, nn});
            }
        }
    }
    return dst;
}


int main(){
    fastio;

    cin >> n >> k >> m;
    lnk.resize(n);
    forf(i, 0, k){
        ll a; cin >> a;
        imp.pb(a-1);
    } sortv(imp);

    forf(j, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    for(ll i : imp) DST1[i]=DIJK1(i);
    for(ll i : imp) for(ll j : imp) if(i<j) DST2[i][j]=DIJK2(i, j);



    ll mn=inf*910191;
    do{
        bool c=false;
        forf(i, 0, k/2) if(imp[i*2]>imp[i*2+1]) c=true;
        if(c) continue;

        vi DST(n);

        forf(j, 0, k/2){
            forf(i, 0, n) DST[i]+=DST2[imp[j*2]][imp[j*2+1]][i];
        }
        if(k%2){
            forf(i, 0, n) DST[i]+=DST1[imp[k-1]][i];
        }
        forf(i, 0, n) mn=min(mn, DST[i]);
    }while(next_permutation(all(imp)));

    cout << mn;


    return 0;
}
