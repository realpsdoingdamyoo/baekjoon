#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


ll v, e, st;
vpii lnk[2][20005];
vi dist[2];

void dijk(ll k){
    forf(i, 0, v+1) dist[k][i]=linf;
    priority_queue<pii> pq;

    dist[k][st]=0;
    pq.push({0, st});
    while(!pq.empty()){
        ll pdist=-pq.top()[0];
        ll pnode=pq.top()[1];
        if(dist[k][pnode]<pdist){pq.pop(); continue;}
        pq.pop();
        forf(i, 0, lnk[k][pnode].size()){
            ll nnode=lnk[k][pnode][i][0];
            ll ndist=pdist+lnk[k][pnode][i][1];
            if(ndist<dist[k][nnode]){
                dist[k][nnode]=ndist;
                pq.push({-ndist, nnode});
            }
        }
    }
}

int main()
{
	fastio;

    cin >> v >> e >> st;
    dist[0].resize(20005);
    dist[1].resize(20005);
    repeat(e){
        ll st, en, x; cin >> st >> en >> x;
        lnk[0][st].pb({en, x});
        lnk[1][en].pb({st, x});
    }
    dijk(0); dijk(1);
    ll mx=0;
    forf(i, 1, v+1) {
        mx=max(mx, dist[0][i]+dist[1][i]);
    }
    cout << mx;
    return 0;
}
