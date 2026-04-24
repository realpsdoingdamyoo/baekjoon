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

ll n, q, c;
vvi lnk;
vi dp, dep;
V<array<ll, 17>> spt;

ll dfs(ll pnt, ll pre, ll depth){
    dp[pnt]=1; spt[pnt][0]=pre; dep[pnt]=depth;
    for(ll i : lnk[pnt])
        if(i!=pre)
            dp[pnt]+=dfs(i, pnt, depth+1);
    return dp[pnt];
}

void sparse_table(){
    forf(j, 1, 17){
        forf(i, 1, n+1){
            spt[i][j]=spt[spt[i][j-1]][j-1];
        }
    }
}

ll lca(ll a, ll b){
    if(dep[a]>dep[b]) swap(a, b);
    ll diff=dep[b]-dep[a];
    forb(i, 17, 0){
        if(diff&(1<<i)) b=spt[b][i];
    }

    if(a==b) return a;

    forb(i, 17, 0){
        if(spt[a][i]!=spt[b][i]){
            a=spt[a][i]; b=spt[b][i];
        }
    }

    return spt[a][0];
}

void solve(ll T){
    cin >> n >> q >> c;
    lnk.resize(n+1); dp.resize(n+1);
    spt.resize(n+1); dep.resize(n+1);
    forf(i, 0, n+1) forf(j, 0, 17) spt[i][j]=0;

    forf(i, 0, n+1) lnk[i].clear();
    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b); lnk[b].pb(a);
    }
    dfs(c, 0, 0);
    sparse_table();

    cout << "Case #" << T << ":\n";

    ll C=c;
    while(q--){
        ll a, b; cin >> a >> b;
        if(a==0) C=b;
        else{
            if(lca(C, b)!=b){
                cout << dp[b] << "\n";
            }
            else if(b==C) cout << n << "\n";
            else{
                ll fC=C;
                forb(i, 17, 0){
                    if(spt[fC][i]==0) continue;
                    if(dep[spt[fC][i]]>dep[b]) fC=spt[fC][i];
                }
                cout << n-dp[fC] << "\n";
            }

        }
    }

}

int main() {
    fastio;

    ll t; cin >> t;
    forf(i, 1, t+1) solve(i);


    return 0;
}
