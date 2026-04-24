#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, m, c, cp;
bool rt[303030];
vector<int> lnk[303030];
int dor[303030], cnt[303030];

int dfs(int p){
    int ret=dor[p]=++c;

    cnt[p]=!rt[p];
    for(int i : lnk[p]){
        if(dor[i]) ret=min(ret, dor[i]);
        else{
            int st=dfs(i);
            if((!rt[i] && st>=dor[p]) || rt[i]) cnt[p]++;
            ret=min(ret, st);
        }
    }
    return ret;
}

signed main() {
    fastio;

	cin >> n >> m;
	for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
	}

    for(int i=1; i<=n; i++) if(!dor[i])
        rt[i]=true, dfs(i), cp++;

    int ans=0;
    for(int i=1; i<=n; i++) if(n-(cp+cnt[i])==m-lnk[i].size()) ans+=i;
    cout << ans;

	return 0;
}
