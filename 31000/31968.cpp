#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int up[303030], sz[303030];
int a[303030], b[303030];

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
int p[303030];
vector<int> lnk[303030];

void dfs(int P, int Pre){
    for(int i : lnk[P]) if(i!=Pre){
        p[i]=P; dfs(i, P);
    }
}

void solve(){
    int s;
    cin >> n >> s; r=0;
    b[0]=s;
    for(int i=1; i<=n; i++){
        int x, P; cin >> x >> P;
        if(x<0) a[i]=-x; else b[i]=x;
        lnk[P].push_back(i);
        lnk[i].push_back(P);
    }

    dfs(r, -1);
    for(int i=0; i<=n; i++) up[i]=i, sz[i]=1;
    for(int i=0; i<=n; i++) if(i!=r) pq.push({a[i], b[i], i});

    int ans=-inf;
    while(1){
        while(pq.size() && (a[Find(pq.top().id)]!=pq.top().a || b[Find(pq.top().id)]!=pq.top().b)) pq.pop();
        if(pq.size()==0) break;
        Node x=pq.top(); pq.pop();
        x.id=Find(x.id);
        int fxid=Find(x.id);
        Union(p[x.id], x.id);
        if(a[Find(0)]==0) ans=max(ans, b[Find(0)]-s);
        if(Find(x.id)==fxid) p[x.id]=p[p[x.id]];
        if(Find(x.id)!=Find(r)) pq.push({a[Find(x.id)], b[Find(x.id)], Find(x.id)});
    }


    cout << ans << "\n";
}

signed main(){
    fastio;

    solve();

    return 0;
}
