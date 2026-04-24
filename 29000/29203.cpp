#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M;
vector<array<int, 3>> lnk[202020];
array<int, 2> edg[202020];
int X[202020], U[202020];

priority_queue<array<int, 2>> st[202020];

int g[202020];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

array<int, 2> add(array<int, 2> a, array<int, 2> b) {
    Union(a[1], b[1]); return {a[0]+b[0], Find(a[1])};
}

void merge(priority_queue<array<int, 2>>& s, priority_queue<array<int, 2>>& x) {
    if (s.size()<x.size()) swap(s, x);
    vector<array<int, 2>> tmp;
    while (x.size()) tmp.push_back(add(s.top(), x.top())), s.pop(), x.pop();
    for (array<int, 2> i : tmp) s.push(i);
}

void DFS(int p, int x, int c, int idx) {
    for (array<int, 3> i : lnk[p]) if (i[0]!=x) {
        DFS(i[0], p, i[1], i[2]);
        merge(st[p], st[i[0]]);
    }
    st[p].push({c, idx});
    if (!X[p]) st[p].pop();
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=1; i<=M; i++) {int x; cin >> x; X[x]=1;}
    for (int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c, i}); lnk[b].push_back({a, c, i});
    }

    DFS(1, 0, inf, inf);

    int r=0;
    while (st[1].size()) r+=st[1].top()[0], U[st[1].top()[1]]=1, st[1].pop();
    cout << r << "\n";

    vector<int> use;
    for (int i=1; i<N; i++) if (U[Find(i)]) use.push_back(i);

    cout << use.size() << "\n";
    for (int i : use) cout << i << " ";


    return 0;
}
