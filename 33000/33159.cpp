#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, q, c;
int dor[303030], dep[303030];
int sp[303030][20];
vector<int> lnk[303030];

void dfs(int p, int pre, int d){
    dor[p]=c++; dep[p]=d;
    sp[p][0]=pre;
    for(int i=1; i<20; i++) sp[p][i]=sp[sp[p][i-1]][i-1];
    for(int i : lnk[p]) if(i!=pre) dfs(i, p, d+1);
}

int lca(int a, int b){
    if(dep[a]<dep[b]) swap(a, b);
    for(int i=19; i>=0; i--) if(dep[a]-dep[b]&(1<<i)) a=sp[a][i];
    if(a==b) return a;
    for(int i=19; i>=0; i--) if(sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return sp[a][0];
}

int N;
unordered_map<int, vector<array<int, 2>>> g;
unordered_map<int, int> ds, cnt, isn;

void dp(int p, int pre){
    cnt[p]=isn[p];
    for(array<int, 2> i : g[p]) if(i[0]!=pre){
        dp(i[0], p);
        cnt[p]+=cnt[i[0]];
        ds[p]+=ds[i[0]]+i[1]*cnt[i[0]];
    }
}

void rdp(int p, int pre){
    for(array<int, 2> i : g[p]) if(i[0]!=pre){
        int r=ds[p]-(ds[i[0]]+i[1]*cnt[i[0]]);
        ds[i[0]]+=r; ds[i[0]]+=(N-cnt[i[0]])*i[1];
        rdp(i[0], p);
    }
}

bool cmp(int a, int b){return dor[a]<dor[b];}
void solve(vector<int> v){
    isn.clear(); for(int i : v) isn[i]=1;

    int k=N=v.size();
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<k-1; i++) v.push_back(lca(v[i], v[i+1]));
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    g.clear(); ds.clear(); cnt.clear();
    for(int i=1; i<v.size(); i++){
        int l=lca(v[i-1], v[i]);
        g[l].push_back({v[i], dep[v[i]]-dep[l]});
        g[v[i]].push_back({l, dep[v[i]]-dep[l]});
    }

    dp(v[0], 0);
    rdp(v[0], 0);

    int ret=inf;
    for(int i : v) ret=min(ret, ds[i]);

    cout << ret << "\n";
}

signed main(){
	fastio;

	cin >> n >> q;
	for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
	}
	dfs(1, 0, 0);

	for(int i=0; i<q; i++){
        int a; cin >> a;
        vector<int> v(a);
        for(int& j : v) cin >> j;
        solve(v);
	}

    return 0;
}
