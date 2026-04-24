#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
vector<int> lnk[10101];
multiset<int> st[10101];

bool dfs(int p, int pre, int len){
    for(int i : lnk[p]) if(i!=pre){
        if(!dfs(i, p, len)) return false;
        st[p].insert(*st[i].begin()+1);
    }

    if(lnk[p].size()%2==1) st[p].insert(0);
    multiset<int> pst;
    while(st[p].size()>=2){
        int en=*prev(st[p].end());
        if(*st[p].begin()+en>len){
            pst.insert(en);
            st[p].erase(prev(st[p].end()));
            continue;
        }

        st[p].erase(prev(st[p].end()));
        multiset<int>::iterator it=prev(st[p].upper_bound(len-en));
        st[p].erase(it);
    }

    if(pst.size()+st[p].size()>=2) return false;
    else if(pst.size()>st[p].size()) swap(pst, st[p]);
    return true;
}

signed main(){
	fastio;

	cin >> n;
	for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
	}

	for(int i=1; i<=n; i++) m+=lnk[i].size()%2;
	cout << m/2 << " ";

	int s=0, e=n;
	while(s<=e){
        int m=s+e>>1;
        for(int i=1; i<=n; i++) st[i].clear();
        if(dfs(1, 0, m)) e=m-1;
        else s=m+1;
	}
	cout << s;

    return 0;
}
