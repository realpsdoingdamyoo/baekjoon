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

ll n, k, q, X=300, s, e;
vi v;
V<tii> query;

ll cnt[101010];
ll dnt[500];
list<ll> dq[101010];

bool cmp(tii a, tii b){
    if(a[0]/X!=b[0]/X) return a[0]/X<b[0]/X;
    else return a[1]<b[1];
}

void P(ll x, ll fb){
    ll dst=0;
    auto& d=dq[v[x]];

    if(d.size()){
        dst=d.back()-d.front();
        cnt[dst]--; dnt[dst/X]--;
    }
    if(fb==0) d.push_front(x);
    else d.push_back(x);

    dst=d.back()-d.front();
    cnt[dst]++; dnt[dst/X]++;
}

void M(ll x, ll fb){
    auto& d=dq[v[x]];

    ll dst=d.back()-d.front();
    cnt[dst]--; dnt[dst/X]--;
    if(fb==0) d.pop_front();
    else d.pop_back();
    if(d.size()){
        dst=d.back()-d.front();
        cnt[dst]++; dnt[dst/X]++;
    }
}

ll mos(pii Q){

    while(Q[0]<s) P(--s, 0);
    while(Q[1]>e) P(++e, 1);
    while(Q[0]>s) M(s++, 0);
    while(Q[1]<e) M(e--, 1);

    forb(i, 100000/X, 0){
        if(dnt[i]!=0){
            forb(j, (i+1)*X, i*X){
                if(cnt[j]!=0)
                    return j;
            }
        }
    }
    return 0;
}

int main(){
    fastio;

    cin >> n >> k;

    v.resize(n);

    forf(i, 0, n) cin >> v[i];
    forf(i, 0, n) v[i]--;

    cin >> q;
    forf(i, 0, q){
        ll a, b; cin >> a >> b;
        query.pb({a-1, b-1, i});
    }
    sortc(query, cmp);

    vi ans(q);

    s=query[0][0]; e=query[0][1];
    forf(i, s, e+1) P(i, 1);
    ans[query[0][2]]=mos({query[0][0], query[0][1]});

    forf(j, 1, q){
        tii i=query[j];
        ans[i[2]]=mos({i[0], i[1]});
    }
    forf(i, 0, q) cout << ans[i] << "\n";

    return 0;
}
