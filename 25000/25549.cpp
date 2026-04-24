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

vi lnk[202020];
set<ll> st[202020];
ll mex[202020];

void dfs(ll pnt, ll pre){
    for(ll i : lnk[pnt])
        if(i!=pre)
            dfs(i, pnt);
    for(ll i : lnk[pnt]){
        if(i!=pre) mex[pnt]=max(mex[pnt], mex[i]);
        if(i!=pre && st[i].size()>st[pnt].size())
            swap(st[i], st[pnt]);
    }
    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        while(st[i].size()){
            auto it=st[i].begin();
            st[pnt].insert(*it);
            st[i].erase(it);
        }
    }
    while(st[pnt].find(mex[pnt])!=st[pnt].end()) mex[pnt]++;
}

int main(){
    fastio;

    ll n, rt; cin >> n;

    forf(i, 1, n+1){
        ll a; cin >> a;
        if(a==-1) rt=i;
        else{
            lnk[i].pb(a);
            lnk[a].pb(i);
        }
    }
    forf(i, 1, n+1){
        ll a; cin >> a;
        st[i].insert(a);
    }

    dfs(rt, -1);

    forf(i, 1, n+1) cout <<mex[i] << "\n";

    return 0;
}
