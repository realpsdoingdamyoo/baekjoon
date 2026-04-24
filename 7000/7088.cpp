#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


vi getpi(string p){
    int m=p.length(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vi kmp(string s, string p){
    int n=s.length(), m=p.length(), j=0;
    vi pi=getpi(p);
    vi ans;
    for(int i=0; i<n; i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1) {ans.push_back(i-j); j=pi[j];}
            else j++;
        }
    }
    return ans;
}

vvi tree;
vector<string> vs;
string p;
vi pi;
ll cnt;

void dfs(ll pnt, ll kpv){
    for(ll npnt : tree[pnt]){
        ll j=kpv;
        for(int i=0; i<vs[npnt].length(); i++){
            while(j>0 && vs[npnt][i]!=p[j]) j=pi[j-1];
            if(vs[npnt][i]==p[j]){
                if(j==p.length()-1) {cnt++; j=pi[j];}
                else j++;
            }
        }
        dfs(npnt, j);
    }
}

int main() {
    ll n; cin >> n;
    tree.resize(n); vs.resize(n);
    forf(i, 0, n-1){
        ll s, e;
        cin >> s >> e; cin >> vs[e];
        tree[s].pb(e);
    }
    cin >> p;
    pi=getpi(p);

    dfs(0, 0);
    cout << cnt << "\n";

    return 0;
}
