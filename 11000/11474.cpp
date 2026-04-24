#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m;
int v[101010];
array<int, 3> u[101010];
int mct[101010], c[101010], out[101010];
vector<int> en[101010], ren[101010];
int s=101010, e=101010;
vector<int> nm;

bool cmp(int a, int b){return c[a]<c[b];}

void dfs(int p){
    for(int i : en[p]){
        if(out[u[i][0]] || out[u[i][1]] || out[u[i][2]]) continue;
        ren[p].push_back(i);
        if(!--mct[u[i][1]]) nm.push_back(u[i][1]);
    }

    out[p]=1;
    if(nm.size()){int x=nm.back(); nm.pop_back(); dfs(x);}

    int cnt[2]={0, 0};
    for(int i : ren[p]){
        if(p==u[i][0]) swap(u[i][0], u[i][2]);
        cnt[c[u[i][0]]<c[u[i][1]]]++;
    }
    if(cnt[0]<cnt[1]) c[p]=e++; else c[p]=s--;
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> u[i][0] >> u[i][1] >> u[i][2];
        en[u[i][0]].push_back(i);
        mct[u[i][1]]++;
        en[u[i][2]].push_back(i);
    }

    for(int i=1; i<=n; i++) if(!mct[i]) nm.push_back(i);

    int p=nm.back(); nm.pop_back(); dfs(p);

    for(int i=1; i<=n; i++) v[i]=i;
    sort(v+1, v+n+1, cmp);

    for(int i=1; i<=n; i++) cout << v[i] << " ";

	return 0;
}
