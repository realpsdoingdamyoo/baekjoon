#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, K, L, A[101010];

struct Faker {
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
            if(a<=b && n.a>n.b) return false;
            if(a>b && n.a<=n.b) return true;
            return b<n.b;
        }
    };

    priority_queue<Node> pq;
    int r;
    int p[101010];
    vector<int> lnk[101010];

    void dfs(int P, int Pre){
        for(int i : lnk[P]) if(i!=Pre){
            p[i]=P; dfs(i, P);
        }
    }

    int solve(){
        dfs(r, -1);
        for(int i=1; i<=N; i++) up[i]=i, sz[i]=1;
        for(int i=1; i<=N; i++) if(i!=r) pq.push({a[i], b[i], i});

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

        return a[Find(r)];
    }
} F;

signed main() {
    fastio;

    cin >> N >> K >> L;
    for (int i=1; i<=N; i++) cin >> A[i];

    int s=0, e=1e9;

    for (int i=1; i<K; i++) F.lnk[i+1].push_back(i);
    for (int i=N; i>K; i--) F.lnk[i-1].push_back(i);
    F.r=K;

    while (s<=e) {
        int m=s+e>>1, T=L*m*2;

        for (int i=1; i<K; i++) {
            int X=A[i+1]-A[i]-T;
            F.a[i]=max(X, 0LL); F.b[i]=max(-X, 0LL);
        }
        for (int i=N; i>K; i--) {
            int X=A[i]-A[i-1]-T;
            F.a[i]=max(X, 0LL); F.b[i]=max(-X, 0LL);
        }
        F.a[K]=F.b[K]=0;

        if (F.solve()) s=m+1; else e=m-1;
    }
    cout << s;

    return 0;
}
