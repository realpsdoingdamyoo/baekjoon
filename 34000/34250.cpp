#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K, ans;
vector<vector<int>> A;
int B[202020], C[202020], P[202020];

int g[202020];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
int Union(int p, int q) {
    p=Find(p); q=Find(q); if (p==q) return 0;
    int ret=B[p]*C[q]; B[q]+=B[p]; C[q]+=C[p]; g[p]=q;
    return ret;
}

struct Node {
    int B, C, ID;
    bool operator<(const Node &n)const {return B*n.C>C*n.B;}
};
priority_queue<Node> pq;


signed main(){
    fastio;

    cin >> N >> K;
    A.resize(K+1, vector<int>(N+1));
    for (int i=1; i<=K; i++) for (int j=0; j<=N; j++) cin >> A[i][j];
    for (int i=1; i<=K; i++) for (int j=0; j<N; j++) {
        int p=(i-1)*N+j+1; B[p]=A[i][j+1]-A[i][j]; C[p]=A[i][j+1];
        ans-=A[i][j]*A[i][j+1]; B[0]+=A[i][j]*!j;
        pq.push({B[p], C[p], p}); P[p]=(j?p-1:0);
        g[p]=p;
    }

    while (1) {
        while (pq.size() && (B[Find(pq.top().ID)]!=pq.top().B || C[Find(pq.top().ID)]!=pq.top().C)) pq.pop();
        if (!pq.size()) break;

        Node x=pq.top(); pq.pop();
        x.ID=Find(x.ID);
        int fxid=x.ID;

        ans+=Union(P[x.ID], x.ID);
        if (Find(x.ID)==fxid) P[x.ID]=P[P[x.ID]];
        if (Find(x.ID)!=Find(0)) pq.push({B[Find(x.ID)], C[Find(x.ID)], Find(x.ID)});
    }
    cout << ans << "\n";



    return 0;
}
