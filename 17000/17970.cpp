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

ll n;
vi v, u, heu, ans;
vi vp, up;

bool check(ll vs){
    if(!heu[vs]) return false;
    ans.clear();
    ll ve=vs, ue, us;
    ue=us=up[v[vs]]; ans.pb(v[vs]);
    //cout << vs << " " << us << "\n";
    while((ve+1)%n!=vs){
        //cout << vs << " " << ve << "\n";
        if(v[(vs+n-1)%n]==u[(us+n-1)%n]){
            ans.pb(v[(vs+n-1)%n]);
            vs=(vs+n-1)%n; us=(us+n-1)%n;
        }
        else if(v[(vs+n-1)%n]==u[(ue+1)%n]){
            ans.pb(v[(vs+n-1)%n]);
            vs=(vs+n-1)%n; ue=(ue+1)%n;
        }
        else if(v[(ve+1)%n]==u[(us+n-1)%n]){
            ans.pb(v[(ve+1)%n]);
            ve=(ve+1)%n; us=(us+n-1)%n;
        }
        else if(v[(ve+1)%n]==u[(ue+1)%n]){
            ans.pb(v[(ve+1)%n]);
            ve=(ve+1)%n; ue=(ue+1)%n;
        }
        else break;
    }
    if(ans.size()==n) return true;
    for(ll i : ans) heu[vp[i]]=0;
    return false;
}

int main(){
    //fastio;

    cin >> n;
    v.resize(n); u.resize(n); heu.resize(n, 1);
    vp.resize(n); up.resize(n);
    forf(i, 0, n){cin >> v[i]; v[i]--; vp[v[i]]=i;}
    forf(i, 0, n){cin >> u[i]; u[i]--; up[u[i]]=i;}
    forf(i, 0, n){
        if(check(i)){
            for(ll a : ans) cout << a+1 << " ";
            return 0;
        }
        //forf(j, 0, n) cout << heu[j] << " "; cout << "\n";
    }
    cout << "-1";

    return 0;
}
