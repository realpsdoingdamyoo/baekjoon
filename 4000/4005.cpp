#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, m, k, p;

int g[404040];
int Find(int x){return g[x]<0?x:g[x]=Find(g[x]);};
void Union(int a, int b){
    a=Find(a); b=Find(b); if(a==b) return;
    if(-g[a]<-g[b]) swap(a, b); g[a]+=g[b]; g[b]=a;
}

signed main(){
    fastio;

    cin >> n >> m >> k;
    for(int i=1; i<=n*2+m*2; i++) g[i]=-1;
    for(int i=1; i<=k; i++){
        int a, b, c; cin >> a >> b >> c; c^=a*b%2;
        if(c) Union(a, b+n+n+m), Union(a+n+m, b+n);
        else Union(a, b+n), Union(a+n+m, b+n+n+m);
    }

    for(int i=1; i<=n+m; i++){
        if(Find(i)==Find(i+n+m)){
            cout << 0;
            return 0;
        }
        if(i==Find(i)) p++;
    }


    int ret=1;
    while(p-->1) ret=ret*2%(mod-7);
    cout << ret;

	return 0;
}
