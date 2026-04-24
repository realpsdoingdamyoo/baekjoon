#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int up[101010], sz[101010];
int a[101010], b[101010];

int Find(int x){return up[x]==x?x:up[x]=Find(up[x]);}
void Union(int p, int q){
    p=Find(p); q=Find(q);
    if(p==q) return;

    if(b[p]<a[q]) a[p]=a[p]-b[p]+a[q], b[p]=b[q];
    else b[p]=b[p]-a[q]+b[q];
    if(sz[p]<sz[q]) swap(p, q), swap(a[p], a[q]), swap(b[p], b[q]);
    up[q]=p; sz[p]+=sz[q];
}

struct Node{
    int a, b, id;
    bool operator<(const Node &n)const{
		if(a<=b && n.a<=n.b) return a>n.a;
		else if(a<=b && n.a>n.b) return false;
		else if(a>b && n.a<=n.b) return true;
		else return b<n.b;
	}
};

priority_queue<Node> pq;
int n, r;
int p[101010];
vector<int> lnk[101010];

void dfs(int P, int Pre){
    for(int i : lnk[P]) if(i!=Pre){
        p[i]=P; dfs(i, P);
    }
}

void solve(){
    cin >> n; r=1;
    for(int i=2; i<=n; i++) cin >> a[i] >> b[i];
    for(int i=0; i<n-1; i++){
        int x, y; cin >> x >> y;
        lnk[x].push_back(y);
        lnk[y].push_back(x);
    }

    dfs(r, -1);
    for(int i=1; i<=n; i++) up[i]=i, sz[i]=1;
    for(int i=1; i<=n; i++) if(i!=r) pq.push({a[i], b[i], i});

    while(1){
        while(pq.size() && (a[Find(pq.top().id)]!=pq.top().a || b[Find(pq.top().id)]!=pq.top().b)) pq.pop();
        if(pq.size()==0) break;
        Node x=pq.top(); pq.pop();
        x.id=Find(x.id);
        int fxid=Find(x.id);
        Union(p[x.id], x.id);
        if(Find(x.id)==fxid) p[x.id]=p[p[x.id]];
        if(Find(x.id)!=Find(r)) pq.push({a[Find(x.id)], b[Find(x.id)], Find(x.id)});
    }

    cout << a[Find(r)] << "\n";

    a[1]=b[1]=0;
    for(int i=1; i<=n; i++) lnk[i].clear();
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
