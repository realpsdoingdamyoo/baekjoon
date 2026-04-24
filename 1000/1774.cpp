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
    ll v, e, cost=0, x;
    vvi sep;
    vi team;
    V<tii> lnk;

    cin >> v >> x;
    sep.resize(v);
    team.resize(v);

    vpii loc(v);
    forf(i, 0, v) cin >> loc[i][0] >> loc[i][1];
    forf(i, 0, x){
        ll a, b; cin >> a >> b;
        lnk.pb({0, a-1, b-1});
    }

    forf(i, 0, v){
        forf(j, 0, v){
            ll a=(ll)(100000*sqrt(pow(loc[i][0]-loc[j][0], 2)+pow(loc[i][1]-loc[j][1], 2)));
            if(i<j) lnk.pb({a, i, j});
        }
    }

    sortv(lnk);

    forf(i, 0, v) sep[i].pb(i), team[i]=i;
    for(tii t : lnk){
        if(team[t[1]]!=team[t[2]]){
            cost+=t[0];
            if(sep[team[t[1]]].size()<sep[team[t[2]]].size()) swap(t[1], t[2]);

            ll t2=team[t[2]];
            for(ll i : sep[team[t[2]]]){
                sep[team[t[1]]].pb(i);
                team[i]=team[t[1]];
            }
            sep[t2].clear();
        }
    }

    printf("%.2lf", (lf)cost/100000);


    return 0;
}
