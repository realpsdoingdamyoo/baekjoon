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

void prp(PQ<pii> pq){
    cout <<"[";
    while(pq.size()){
        cout <<pq.top()[0] << " " <<pq.top()[1] << " / ";
        pq.pop();
    }
    cout <<"]\n";
}

void solve(){
    ll n, m; cin >> n >> m;
    vi v(m+1), pl(n+1), nl(m+1); forf(i, 1, m+1) cin >> v[i];
    PQ<pii> pq;

    forf(i, 1, m+1){
        if(v[i]==0) continue;
        if(pl[v[i]]==0) pq.push({-i, v[i]});
        nl[pl[v[i]]]=i; pl[v[i]]=i;
    }



    vi ans;
    forf(i, 1, m+1){
        if(pq.size()==0){
            if(v[i]==0) ans.pb(0);
            if(nl[i]) pq.push({-nl[i], v[i]});
            continue;
        }

        if(v[i]!=0 && pq.top()[1]==v[i]){
            cout << "NO\n";
            return;
        }

        if(v[i]!=0){
            if(nl[i]) pq.push({-nl[i], v[i]});
            continue;
        }

        pii t=pq.top(); pq.pop();
        ans.pb(t[1]);
    }
    cout << "YES\n";
    for(ll i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    fastio;

    ll t; cin >> t;
    forf(i, 0, t) solve();

    return 0;
}
