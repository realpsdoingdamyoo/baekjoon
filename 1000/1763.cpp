#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int up[1010];
int a[1010], b[1010];

int Find(int x){return up[x]==x?x:Find(up[x]);}
int Union(int p, int q){
    p=Find(p); q=Find(q);
    if(p==q) return 0;

    int ret=a[q]*b[p];
    a[q]+=a[p]; b[q]+=b[p]; up[p]=q;
    return ret;
}

struct Node{
    int a, b, id;
    bool operator<(const Node &n)const{
		return a*n.b<b*n.a;
	}
};

priority_queue<Node> pq;
int n, r;
int c[1010], p[1010];
vector<int> lnk[1010];

void dfs(int P, int Pre){
    for(int i : lnk[P]) if(i!=Pre){
        p[i]=P; dfs(i, P);
    }
}

signed main(){
    //fastio;

    cin >> n >> r;
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=0; i<n-1; i++){
        int x, y; cin >> x >> y;
        lnk[x].push_back(y);
        lnk[y].push_back(x);
    }

    dfs(r, -1);
    for(int i=1; i<=n; i++) up[i]=i;
    for(int i=1; i<=n; i++) a[i]=c[i], b[i]=1;
    for(int i=1; i<=n; i++) if(i!=r) pq.push({a[i], b[i], i});

    int ret=0;
    while(1){
        while(pq.size() && (a[Find(pq.top().id)]!=pq.top().a || b[Find(pq.top().id)]!=pq.top().b)) pq.pop();
        if(pq.size()==0) break;
        Node x=pq.top(); pq.pop();
        x.id=Find(x.id);
        int fxid=Find(x.id);
        ret+=Union(p[x.id], x.id);
        if(Find(x.id)==fxid) p[x.id]=p[p[x.id]];
        if(Find(x.id)!=Find(r)) pq.push({a[Find(x.id)], b[Find(x.id)], Find(x.id)});
    }
    for(int i=1; i<=n; i++) ret+=c[i];
    cout << ret;

    return 0;
}
