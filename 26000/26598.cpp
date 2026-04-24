#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vector<string> s(1000);
vpii salp;
ll n, m;

void dfs(ll x, ll y, char c){
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(s[x][y]!=c) return;
    salp.push_back({x, y});
    s[x][y]='0';
    for(ll i=0; i<4; i++){
        dfs(x+dir[i][0], y+dir[i][1], c);
    }
}

bool dfs_rect(ll x, ll y){
    if(s[x][y]=='0') return true;
    salp.resize(0);
    dfs(x, y, s[x][y]);
    ll minx=10000, maxx=-1, miny=10000, maxy=-1;
    for(ll i=0; i<salp.size(); i++){
        minx=min(minx, salp[i][0]);
        maxx=max(maxx, salp[i][0]);
        miny=min(miny, salp[i][1]);
        maxy=max(maxy, salp[i][1]);
    }
    if(salp.size()==(maxx-minx+1)*(maxy-miny+1)) return true;
    return false;
}

int main(){
    fastio;

    cin >> n >> m;
    bool flag=true;
    for(ll i=0; i<n; i++) cin >> s[i];

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            flag=flag&&dfs_rect(i, j);
        }
    }
    cout << (flag?"dd":"BaboBabo");
    return 0;
}
