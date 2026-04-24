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

int main() {
    fastio;

    ll n, m, q; cin >> n >> m >> q;
    map<ll, V<string>> gr;
    map<string, ll> pr;
    map<string, ll> hv;

    forf(i, 0, n){
        ll g, p; string h;
        cin >> g >> h >> p;
        gr[g].pb(h);
        pr[h]=p;
    }
    forf(i, 0, q){
        ll t; cin >> t;
        if(t==1){
            string a; ll b;
            cin >> a >> b;
            if(pr[a]*b<=m){
                m-=pr[a]*b;
                hv[a]+=b;
            }
        }
        else if(t==2){
            string a; ll b;
            cin >> a >> b;
            b=min(b, hv[a]);
            m+=pr[a]*b;
            hv[a]-=b;
        }
        else if(t==3){
            string a; ll b;
            cin >> a >> b;
            pr[a]+=b;
        }
        else if(t==4){
            ll a,  b;
            cin >> a >> b;
            for(string s : gr[a]) pr[s]+=b;
        }
        else if(t==5){
            ll a,  b;
            cin >> a >> b;
            for(string s : gr[a]){
                pr[s]=pr[s]*(100+b)/100;
                pr[s]-=pr[s]%10;
            }
        }
        else if(t==6){
            cout << m << "\n";
        }
        else{
            ll M=m;
            for(pair<string, ll> p : pr){
                M+=p.second*hv[p.first];
            }
            cout << M << "\n";
        }
    }


    return 0;
 }
