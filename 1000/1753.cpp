#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll v, e, st;
vpii lnk[20005];
vi dist(20005);

void dijkstra(){
    forf(i, 0, v+1) dist[i]=linf;
    priority_queue<pii> pq;

    dist[st]=0;
    pq.push({0, st});
    while(!pq.empty()){
        ll pdist=-pq.top()[0];
        ll pnode=pq.top()[1];
        if(dist[pnode]<pdist){pq.pop(); continue;}
        pq.pop();
        forf(i, 0, lnk[pnode].size()){
            ll nnode=lnk[pnode][i][0];
            ll ndist=pdist+lnk[pnode][i][1];
            if(ndist<dist[nnode]){
                dist[nnode]=ndist;
                pq.push({-ndist, nnode});
            }
        }
    }

}

int main()
{
	fastio;

    cin >> v >> e >> st;
    repeat(e){
        ll st, en, x; cin >> st >> en >> x;
        lnk[st].pb({en, x});
        //lnk[en].pb({st, x});
    }
    dijkstra();
    forf(i, 1, v+1) {
        if(dist[i]==linf) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
