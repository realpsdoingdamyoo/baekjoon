#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m;
int dist[1<<21], pre[1<<21], sht[1<<21], ctr[21];
vector<int> lnk[21];

int bfs(){
    int cur, nxt;
    queue<int> q; q.push((1<<n)-1);
    for(int i=0; i<(1<<n); i++) dist[i]=-1;
    dist[(1<<n)-1]=0;

    while(q.size()){
        int p=q.front(); cur=0; q.pop();
        for(int i=0; i<n; i++) ctr[i]=0;

        for(int i=0; i<n; i++) if(p&(1<<i)){
            for(int x : lnk[i]){
                ctr[x]++; cur|=1<<x;
            }
        }
        for(int i=0; i<n; i++) if(p&(1<<i)){
            nxt=cur;
            for(int x : lnk[i]) if(ctr[x]<=1) nxt&=~(1<<x);
            if(dist[nxt]==-1){
                dist[nxt]=dist[p]+1;
                q.push(nxt);
                pre[nxt]=p;
                sht[nxt]=i;
                if(nxt==0) return dist[0];
            }
        }
    }
    return inf;
}


void print(int p){
    if(p==(1<<n)-1) return;
    print(pre[p]); cout << " " << sht[p];
}

bool solve(){
    cin >> n >> m;
    if(n==0&&m==0) return false;
    for(int i=0; i<n; i++) lnk[i].clear();
    for(int i=1; i<=m; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    int ret=bfs();

    if(ret==inf){
        cout << "Impossible\n";
        return true;
    }

    cout << ret << ":";
    print(0); cout << "\n";
    return true;
}

signed main(){
    fastio;

    while(solve()){}

	return 0;
}
