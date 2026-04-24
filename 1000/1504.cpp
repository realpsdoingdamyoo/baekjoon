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
const ll inf=2147483647, linf=9223372036854775807/10;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll v, e, p1, p2;
vpii lnk[20005];
vi dist(20005);

ll dijk(ll st, ll en){
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
    return dist[en];
}

int main()
{
	fastio;

    cin >> v >> e;
    repeat(e){
        ll st, en, x; cin >> st >> en >> x;
        lnk[st].pb({en, x});
        lnk[en].pb({st, x});
    }
    cin >> p1 >> p2;
    cout << (min(dijk(1, p1)+dijk(p1, p2)+dijk(p2, v), dijk(1, p2)+dijk(p2, p1)+dijk(p1, v))>=linf?-1:min(dijk(1, p1)+dijk(p1, p2)+dijk(p2, v), dijk(1, p2)+dijk(p2, p1)+dijk(p1, v)));

    return 0;
}
