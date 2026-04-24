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
#define cf; cout.flush();

ll n, m;
ll N, M;
V<string> brd;
vvi lnk;
vi match;
V<bool> cons;
vpii peo, exi;
vvi dist;
map<pii, ll> mexi;

void init(){
    lnk.resize(N);
    forf(i, 0, N) lnk[i].clear();
    match.resize(M);
    cons.resize(M);
}

bool dfs(ll x){
    for(ll i : lnk[x]){
        if(cons[i]) continue;
        cons[i]=true;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=x; return true;
        }
    }
    return false;
}

ll matching(){
    ll r=0;
    forf(i, 0, M) match[i]=-1;
    forf(i, 0, N){
        forf(j, 0, M) cons[j]=false;
        r+=dfs(i);
    }
    return r++;
}

int main() {
    fastio;

    cin >> n >> m; brd.resize(n);
    forf(i, 0, n) cin >> brd[i];

    forf(i, 0, n){
        forf(j, 0, m){
            if(brd[i][j]=='.') peo.pb({i, j});
            if(brd[i][j]=='D'){
                exi.pb({i, j});
                mexi[{i, j}]=exi.size()-1;
            }
        }
    }

    if(exi.size()==0){
        cout << "impossible\n";
        return 0;
    }

    dist.resize(peo.size());
    forf(i, 0, peo.size()) dist[i].resize(exi.size());

    forf(i, 0, peo.size()){
        forf(j, 0, exi.size()) dist[i][j]=inf;
        ll vsd[12][12]={};
        queue<tii> q;
        q.push({peo[i][0], peo[i][1], 0});

        while(q.size()){
            tii t=q.front(); q.pop();
            if(vsd[t[0]][t[1]]) continue;
            vsd[t[0]][t[1]]=1;
            if(brd[t[0]][t[1]]=='X') continue;
            if(brd[t[0]][t[1]]=='D'){
                dist[i][mexi[{t[0], t[1]}]]=t[2];
                continue;
            }
            forf(j, 0, 4){
                ll x=t[0]+dir4[j][0], y=t[1]+dir4[j][1];
                if(x<0 || x>=n || y<0 || y>=m) continue;
                if(vsd[x][y]) continue;
                q.push({x, y, t[2]+1});
            }
        }
        forf(j, 0, exi.size()){
            if(dist[i][j]!=inf) break;
            if(j==exi.size()-1){
                cout << "impossible\n";
                return 0;
            }
        }
    }


    ll s=1, e=144;
    while(s<=e){
        ll mid=(s+e)/2;

        N=peo.size();
        M=mid*exi.size();
        init();

        forf(i, 0, N){
            forf(j, 0, M){
                ll J=j/mid, T=j%mid+1;
                if(dist[i][J]<=T){
                    lnk[i].pb(j);
                }
            }
        }
        if(matching()!=N) s=mid+1;
        else e=mid-1;
    }
    cout << s;

    return 0;
}
