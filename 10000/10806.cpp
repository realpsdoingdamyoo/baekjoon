#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int N, M;
vector<int> lnk[101010];
set<int> lnk2[101010];

int g[101010];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

int cc=0;

int P[101010];
void dfs(int p) {
    for (int i : lnk[p]) {
        if (P[i]==-1) P[i]=p, dfs(i);
        else if (P[i]==p) Union(i, p);
        else if (i!=P[p]) while (Find(p)!=Find(i)) Union(p, P[Find(p)]);
    }
}

vector<int> lf;
void dfs2(int p, int x) {
    if (lnk2[p].size()==1) lf.push_back(p);
    for (int i : lnk2[p]) if (i!=x) dfs2(i, p);
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=0; i<N; i++) g[i]=i;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    fill(P+1, P+N, -1);
    dfs(0);

    for (int i=0; i<N; i++) for (int j : lnk[i]) {
        if (Find(i)!=Find(j)) lnk2[Find(i)].insert(Find(j));
    }

    int x=0;
    for (int i=0; i<N; i++) if (i==Find(i)) x=i;

    fill(P+1, P+N+1, 0);
    dfs2(x, -1);

    cout << (lf.size()+1)/2 << "\n";
    for (int i=0; i<(lf.size()+1)/2; i++) {
        cout << lf[i]+1 << " " << lf[(i+lf.size()/2)%lf.size()]+1 << "\n";
    }

    return 0;
}
