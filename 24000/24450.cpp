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

ll n, m, ans;
vvi v;

bool chk(vi h, vi w, ll s){
    if(h[h.size()-1]!=n || w[w.size()-1]!=m) return false;
    forf(i, 1, h.size()){
        forf(j, 1, w.size()){
            ll os=v[h[i]][w[j]]-v[h[i-1]][w[j]]-v[h[i]][w[j-1]]+v[h[i-1]][w[j-1]];
            if(os!=s) return false;
        }
    }
    return true;
}

int main(){
    fastio;

    cin >> n >> m;
    v.resize(n+1); forf(i, 0, n+1) v[i].resize(m+1);
    forf(i, 1, n+1){
        forf(j, 1, m+1){
            cin >> v[i][j];
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }

    forf(i, 1, n+1){
        forf(j, 1, m+1){
            ll s=v[i][j];
            vi h, w;
            h.pb(0); w.pb(0);
            h.pb(i); w.pb(j);

            forf(k, i+1, n+1){
                ll os=v[k][j]-v[h[h.size()-1]][j];
                if(s==os) h.pb(k);
            }
            forf(l, j+1, m+1){
                ll os=v[i][l]-v[i][w[w.size()-1]];
                if(s==os) w.pb(l);
            }
            ans+=chk(h, w, s);

        }
    }
    cout << ans-1;




    return 0;
}
