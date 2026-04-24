#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int N, M;
vector<int> lnk[202020];

int dep[202020], sp[202020][20];
void dfs(int p, int x) {
    for (int i : lnk[p]) if (i!=x) {
        dep[i]=dep[p]+1; sp[i][0]=p;
        for (int j=1; j<20; j++) sp[i][j]=sp[sp[i][j-1]][j-1];
        dfs(i, p);
    }
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=19; i>=0; i--) if (dep[a]-dep[b]&(1<<i)) a=sp[a][i];
    if (a==b) return a;
    for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return sp[a][0];
}

int dist(int a, int b) {
    return dep[a]+dep[b]-2*dep[lca(a, b)];
}

int goup(int p, int x) {
    for (int i=0; i<20; i++) if (x&(1<<i)) p=sp[p][i];
    return p;
}

int sz[202020], co[202020], cp[202020];

void szm(int p, int x) {
    sz[p]=1;
    for (int i : lnk[p]) if (i!=x && !co[i]) szm(i, p), sz[p]+=sz[i];
}
int getc(int p, int x, int s) {
    for (int i : lnk[p]) if (i!=x && !co[i] && sz[i]>=s/2) return getc(i, p, s);
    return p;
}

void decomp(int p, int x) {
    szm(p, 0); p=getc(p, 0, sz[p]); cp[p]=x; co[p]=1;
    for (int i : lnk[p]) if (!co[i]) decomp(i, p);
}

vector<int> tp[202020], up[202020];
void push(vector<int>& v, int d) {
    while (v.size()<=d) v.push_back(0);
    v[d]++;
}

array<int, 2> mrg(array<int, 2> a, array<int, 2> b) {
    if (a[0]<=M ^ a[1]%2==0) a[1]--; if (a[1]<0) a={0, 0};
    if (b[0]<=M ^ b[1]%2==0) b[1]--; if (b[1]<0) b={0, 0};
    if (a[0]==0 || b[0]==0) return {0, 0};


    int d=dist(a[0], b[0]);
    if (d>a[1]+b[1]) return {0, 0};
    if (dep[a[0]]-a[1]<dep[b[0]]-b[1]) swap(a, b);
    if (a[1]>=b[1]+d) return b; if (b[1]>=a[1]+d) return a;
    int x=(a[1]+b[1]-d)/2;
    int m=goup(a[0], a[1]-x);
    return {m, x};
}

int K;
array<int, 2> pr[303030], sf[303030];

int Find(int p, int x) {
    if (p==0) return 0;

    int c=p, r=0;
    while (c) {
        int d1=dist(c, p);
        if (d1<=x) {
            r+=tp[c][min((int)tp[c].size()-1, x-d1)];
        }
        if (cp[c]) {
            int d2=dist(cp[c], p);
            if (d2<=x) {
                r-=up[c][min((int)up[c].size()-1, x-d2)];
            }
        }
        c=cp[c];
    }
    return r;
}

void query() {
    cin >> K;
    for (int i=1; i<=K; i++) {
        int x, y; cin >> x >> y;
        pr[i]=sf[i]={x, 2*y};
    }

    for (int i=2; i<=K; i++) pr[i]=mrg(pr[i-1], pr[i]);
    for (int i=K-1; i>=1; i--) sf[i]=mrg(sf[i+1], sf[i]);
    pr[0]=sf[K+1]={1, N+10};

    int ret=0;
    for (int i=1; i<=K; i++) {
        array<int, 2> x=mrg(pr[i-1], sf[i+1]);
        ret+=Find(x[0], x[1]);
    }
    ret-=(K-1)*Find(pr[K][0], pr[K][1]);
    cout << ret << "\n";
}

signed main(){
    fastio;

    cin >> M;
    for (N=M+1; N<M*2; N++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(N); lnk[N].push_back(a);
        lnk[b].push_back(N); lnk[N].push_back(b);
    }

    dfs(1, 0);
    decomp(1, 0);


    for (int i=1; i<=M; i++) {
        int p=i;
        while (p) {
            push(tp[p], dist(p, i));
            if (cp[p]) push(up[p], dist(cp[p], i));
            p=cp[p];
        }
    }

    for (int i=1; i<=N; i++) {
        if (tp[i].size()==0) tp[i]={0};
        if (up[i].size()==0) up[i]={0};
        for (int j=1; j<tp[i].size(); j++) tp[i][j]+=tp[i][j-1];
        for (int j=1; j<up[i].size(); j++) up[i][j]+=up[i][j-1];
    }

    int Q; cin >> Q;
    while (Q--) query();

    return 0;
}
