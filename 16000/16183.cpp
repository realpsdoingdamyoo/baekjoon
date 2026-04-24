#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, m, ers;
set<int> st[101010];

void Mrg(int p){
    if(st[p].size()!=2) return;
    ers++;
    int a=*st[p].begin(), b=*next(st[p].begin());
    st[p].erase(a); st[a].erase(p); st[a].insert(b);
    st[p].erase(b); st[b].erase(p); st[b].insert(a);
    Mrg(a); Mrg(b);
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        st[a].insert(b);
        st[b].insert(a);
    }

    for(int i=1; i<=n; i++) Mrg(i);
    if(ers==n-2) cout << "Yes";
    else cout << "No";

    return 0;
}
