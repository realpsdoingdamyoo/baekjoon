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


bool solve(){
    ll n, m, k; cin >> n >> m >> k;
    if(n==0 && m==0 && k==0) return false;
    V<vpii> lnk1(n), lnk2(n);

    forf(x, 0, m){
        string s; cin >> s;
        ll a, b; cin >> a >> b;
        a--; b--;
        lnk1[a].pb({-(s=="B"), b});
        lnk1[b].pb({-(s=="B"), a});
        lnk2[a].pb({-(s=="R"), b});
        lnk2[b].pb({-(s=="R"), a});
    }

    map<ll, ll> mp1, mp2;
    PQ<pii> pq1, pq2;
    ll c1=0, c2=0;
    mp1[0]=1; mp2[0]=1;
    for(pii p : lnk1[0]) pq1.push(p);
    for(pii p : lnk2[0]) pq2.push(p);

    while(pq1.size()){
        pii tp=pq1.top(); pq1.pop();
        if(mp1[tp[1]]) continue;
        for(pii p : lnk1[tp[1]]) pq1.push(p);
        c1+=tp[0]; mp1[tp[1]]=1;
    }
    while(pq2.size()){
        pii tp=pq2.top(); pq2.pop();
        if(mp2[tp[1]]) continue;
        for(pii p : lnk2[tp[1]]) pq2.push(p);
        c2+=tp[0]; mp2[tp[1]]=1;
    }

    c1=-c1; c2=n-1+c2;

    //cout << c1 << " " << c2 << " ";

    cout << (c1<=k && k<=c2) << "\n";

    return true;
}

int main(){
    fastio;

    while(solve()){}


    return 0;
}
