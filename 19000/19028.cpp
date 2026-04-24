#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e1;

int N, M;
array<int, 2> edg[252525];
vector<int> rct[252525];

int g[101010];
int Find(int x){return g[x]<0?x:g[x]=Find(g[x]);}
void Union(int a, int b) {
    a=Find(a); b=Find(b);
    if (a!=b) g[a]+=g[b], g[b]=a;
}

vector<int> lnk[101010], rlnk[101010];
int SN[101010], vis[101010], rvis[101010];
vector<int> vsq;

void dfs(int p) {
    vis[p]=1;
    for (int i : lnk[p]) if (!vis[i]) dfs(i);
    vsq.push_back(p);
}
void rdfs(int p, int c) {
    SN[p]=c; rvis[p]=1;
    for (int i : rlnk[p]) if (!rvis[i]) rdfs(i, c);
}

vector<int> pnt;

void sccfind() {
    for (int i : pnt) SN[i]=vis[i]=rvis[i]=0;
    for (int i : pnt) if (!vis[i]) dfs(i);
    int c=0;
    while (vsq.size()) {
        int p=vsq.back(); vsq.pop_back();
        if (!rvis[p]) rdfs(p, ++c);
    }
}

void Clear() {
    for (int i : pnt) lnk[i].clear(), rlnk[i].clear();
    pnt.clear();
}

void dnc(int l, int r, vector<int>& vec) {
    if (l==r) {
        for (int i : vec) rct[l].push_back(i), Union(edg[i][0], edg[i][1]);
        return;
    }

    int m=l+r>>1;

    Clear();

    vector<int> lv, rv;
    for (int i : vec) if (i<=m) {
        int x=Find(edg[i][0]), y=Find(edg[i][1]);
        lnk[x].push_back(y); rlnk[y].push_back(x);
        pnt.push_back(x); pnt.push_back(y);
    }

    sccfind();

    for (int i : vec) {
        if (i<=m) {
            int x=Find(edg[i][0]), y=Find(edg[i][1]);
            if (SN[x]==SN[y]) lv.push_back(i);
            else rv.push_back(i);
        }
        else rv.push_back(i);
    }

    dnc(l, m, lv); dnc(m+1, r, rv);
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) cin >> edg[i][0] >> edg[i][1];
    edg[M+1]=edg[M];
    for (int i=1; i<=N; i++) g[i]=-1;
    vector<int> vec;
    for (int i=1; i<=M; i++) vec.push_back(i);
    dnc(1, M+1, vec);

    int R=0;
    for (int i=1; i<=N; i++) g[i]=-1;
    for (int i=1; i<=M; i++) {
        for (int j : rct[i]) {
            int x=Find(edg[j][0]), y=Find(edg[j][1]);
            if (x!=y) R+=g[x]*g[y], Union(x, y);
        }
        cout << R << '\n';
    }


    return 0;
}
