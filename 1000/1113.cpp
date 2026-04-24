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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

ll n, m;
vvi h;
vvi ret;


void bfs(ll hei){
    V<V<bool>> vsd(n+2, V<bool>(m+2));
    queue<pii> q;
    q.push({0, 0});

    while(q.size()){
        pii tp=q.front(); q.pop();
        if(vsd[tp[0]][tp[1]]) continue;
        vsd[tp[0]][tp[1]]=true;
        ret[tp[0]][tp[1]]=min(ret[tp[0]][tp[1]], hei);

        for(pii d : dir4){
            ll x=tp[0]+d[0], y=tp[1]+d[1];
            if(x<0 || x>=n+2 || y<0 || y>=m+2) continue;
            if(vsd[x][y] || h[x][y]>hei) continue;
            q.push({x, y});
        }
    }
}

int main(){
    fastio;

    cin >> n >> m;
    h.resize(n+2, vi(m+2));
    ret.resize(n+2, vi(m+2));

    forf(i, 1, n+1){
        string s; cin >> s;
        forf(j, 0, m){
            h[i][j+1]=s[j]-'0';
            ret[i][j+1]=9;
        }
    }

    forb(i, 10, 1) bfs(i);

    ll ans=0;
    forf(i, 1, n+1) forf(j, 1, m+1) ans+=ret[i][j]-h[i][j];

    cout << ans;

    return 0;
}
