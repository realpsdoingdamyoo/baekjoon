#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, m, s;
vector<array<int, 3>> qry[20];
vector<array<int, 3>> mst;

int g[202020];
int Find(int x){return g[x]<0?x:Find(g[x]);}
void Union(int a, int b){
    if(-g[a]<-g[b]) swap(a, b);
    g[a]+=g[b]; g[b]=a;
}

void span(){
    s=0;
    vector<array<int, 3>> ret;
    for(int i=0; i<n; i++) g[i]=-1;
    for(array<int, 3> i : mst){
        int a=Find(i[1]), b=Find(i[2]);
        if(a==b) continue;
        Union(a, b);
        ret.push_back(i); s+=i[0];
    }
    mst=ret;
}

signed main(){
	fastio;

	cin >> n >> m;
	while(m--){
        int u, v, c, k;
        cin >> u >> v >> c >> k;
        for(int i=0; i<20; i++){
            if(k&(1<<i)){
                qry[i].push_back({c, u, v});
                u=(u+(1<<i))%n;
                v=(v+(1<<i))%n;
                c=c+(1<<i);
            }
        }
	}

	for(int i=19; i>=0; i--){
        for(int j=mst.size()-1; j>=0; j--)
            mst.push_back({mst[j][0]+(1<<i), (mst[j][1]+(1<<i))%n, (mst[j][2]+(1<<i))%n});
        for(array<int, 3> e : qry[i]) mst.push_back(e);
        sort(mst.begin(), mst.end());
        span();
	}


	if(mst.size()==n-1) cout << s << "\n";
	else cout << "-1\n";

    return 0;
}
