#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M;
int L[101010], U[101010], V[101010];
vector<array<int, 2>> LE[101010], RE[101010];
int LC[101010], RC[101010];

int g[101010];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> L[i], U[i]=i;
    sort(U+1, U+N+1, [&](int a, int b){return L[a]<L[b];});
    for (int i=1; i<=N; i++) V[U[i]]=i;
    sort(L+1, L+N+1);

    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        LE[max(V[a], V[b])].push_back({V[a], V[b]});
        RE[min(V[a], V[b])].push_back({V[a], V[b]});
    }

    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=1; i<=N; i++) {
        LC[i]=LC[i-1]+1;
        for (array<int, 2> j : LE[i]) {
            if (Find(j[0])!=Find(j[1])) Union(j[0], j[1]), LC[i]--;
        }
    }
    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=N; i>=1; i--) {
        RC[i]=RC[i+1]+1;
        for (array<int, 2> j : RE[i]) {
            if (Find(j[0])!=Find(j[1])) Union(j[0], j[1]), RC[i]--;
        }
    }

    for (int i=1; i<N; i++) if (L[i]!=L[i+1]) {
        if (LC[i]+RC[i+1]-1<=min(i, N-i)) {
            cout << L[i];
            return 0;
        }
    }
    cout << "-1";

    return 0;
}
