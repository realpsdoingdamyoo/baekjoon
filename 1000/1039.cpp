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


int main(){
    fastio;

    S s; cin >> s;
    ll k; cin >> k;
    map<S, ll> vsd;
    vsd[s]=1;

    V<S> vans;

    forf(i, 0, k){
        V<S> v;
        for(auto i : vsd) v.pb(i.first);
        vsd.clear();

        forf(i, 0, v.size()){
            forf(j, 0, s.length()){
                forf(l, j+1, s.length()){
                    S ns=v[i];
                    swap(ns[j], ns[l]);
                    if(ns[0]!='0') vsd[ns]=1;
                    //cout << "(" << v[i] << " " << ns << ")";
                }
            }
        }
        //for(auto i : vsd) cout << i.first << " "; cout << "\n";
    }

    S ans="";
    for(auto i : vsd){
        auto p=i.first;
        if(ans=="" || ans<p) ans=p;
    }
    if(ans=="") cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}
