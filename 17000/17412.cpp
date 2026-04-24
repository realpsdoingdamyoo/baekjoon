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

ll n, m;
V<vpii> cf; //capa, flow

ll FLOW(ll s, ll e){
    ll ret=0;

    while(1){
        vi from(n+1); from[s]=s;
        queue<ll> q; q.push(s);
        while(q.size() && !from[e]){
            ll p=q.front(); q.pop();
            forf(i, 1, n+1){
                if(cf[p][i][0]>cf[p][i][1] && !from[i]){
                    q.push(i);
                    from[i]=p;
                }
            }
        }
        if(!from[e]) break;

        ll flow=inf;
        for(ll i=e; i!=s; i=from[i]){
            flow=min(flow, cf[from[i]][i][0]-cf[from[i]][i][1]);
        }

        for(ll i=e; i!=s; i=from[i]){
            cf[from[i]][i][1]+=flow;
            cf[i][from[i]][1]-=flow;
        }

        ret+=flow;
    }
    return ret;
}

int main(){
    fastio;

    cin >> n >> m;
    cf.resize(n+1);
    forf(i, 0, n+1) cf[i].resize(n+1);

    forf(i, 0, m){
        ll a, b; cin >> a >> b;
        cf[a][b]={1, 0};
        cf[b][a]={0, 0};
    }

    cout << FLOW(1, 2);


    return 0;
}
