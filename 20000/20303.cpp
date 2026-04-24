#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, K;
int C[30303], U[30303];

int g[30303];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b) {g[Find(a)]=g[Find(b)];}

int bg[3030];

signed main(){
    fastio;

    cin >> N >> M >> K; K--;
    for (int i=1; i<=N; i++) g[i]=i, U[i]=1, cin >> C[i];
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        Union(a, b);
    }

    for (int i=1; i<=N; i++) if (i!=Find(i)) C[Find(i)]+=C[i], U[Find(i)]+=U[i];
    for (int i=1; i<=N; i++) if (i==Find(i)) {
        for (int j=K-U[i]; j>=0; j--) bg[j+U[i]]=max(bg[j+U[i]], bg[j]+C[i]);
    }
    cout << bg[K];

    return 0;
}
