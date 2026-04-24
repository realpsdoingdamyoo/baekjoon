#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

vector<array<int, 3>> vec;
int X[2020], Y[2020], C[2020], g[2020], R;
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

signed main() {
    fastio;

    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i] >> C[i], R-=C[i];
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) vec.push_back({C[i]+C[j]+abs(X[i]-X[j])+abs(Y[i]-Y[j]), i, j});
    sort(vec.begin(), vec.end());

    iota(g+1, g+N+1, 1);
    for (array<int, 3> i : vec) if (Find(i[1])!=Find(i[2])) Union(i[1], i[2]), R+=i[0];
    for (int i=1; i<=N; i++) cout << R+C[i] << " ";

    return 0;
}
