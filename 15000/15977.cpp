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

ll n, m;
V<tii> u;
vpii v;
multiset<pii> s[202020];

void input(){
    cin >> m >> n;
    u.resize(n);
    forf(j, 0, m) forf(i, 0, n) cin >> u[i][j];
    if(m==2) forf(i, 0, n) u[i][2]=u[i][1];
    sortv(u);
    forf(i, 0, n) v.pb({u[i][1], u[i][2]});
}

bool lislen(ll len, pii p){
    if(s[len].size()==0) return true;
    if(s[len].upper_bound(p)==s[len].begin()) return false;
    pii it=*prev(s[len].upper_bound(p));
    if(it[1]<p[1]) return true;
    else return false;
}

void ins(ll len, pii p){
    auto it=s[len].upper_bound(p);
    while(it!=s[len].end()){
        if(p[1]>(*it)[1]) break;
        auto nit=next(it);
        s[len].erase(it);
        it=nit;
    }
    s[len].insert(p);
}

int main(){
    fastio;

    input();
    //forf(i, 0, n) cout << v[i][0] << " " << v[i][1] << "\n";

    s[1].insert(v[0]);
    ll lis=1;
    forf(i, 1, n){
        ll S=1, E=lis, L;
        while(S<=E){
            ll M=(S+E)/2;
            if(lislen(M, v[i])) S=M+1;
            else E=M-1;
        } L=E+1;
        ins(L, v[i]);
        lis=max(lis, L);

        /*forf(j, 1, lis+1){
            cout << j << ") ";
            for(pii p : s[j]) cout << "[" << p[0] << " " << p[1] << "] ";
            cout << "\n";
        }
        cout << "\n";*/
    }

    cout << lis;


    return 0;
}
