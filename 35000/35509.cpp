#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N, M;
array<int, 4> vec[303030];

int g[101010];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        vec[i]={c, a, b, i};
    }

    sort(vec+1, vec+M+1);

    for (int i=1; i<=N; i++) g[i]=i;

    int C=0, mc=0, mx=0;
    for (int i=1; i<=M; i++) {
        if (Find(vec[i][1])!=Find(vec[i][2])) {
            C++;
            g[Find(vec[i][1])]=Find(vec[i][2]);
            mc+=vec[i][0];
        }

        if (C==N-1) {
            mx=vec[i][0];
            break;
        }
    }

    int c2=0;
    vector<int> ret;
    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=M; i>=1; i--) if (vec[i][0]<=mx) {
        if (Find(vec[i][1])!=Find(vec[i][2])) {
            g[Find(vec[i][1])]=Find(vec[i][2]);
            c2+=vec[i][0];
            ret.push_back(vec[i][3]);
        }
    }

    cout << "NO\n";
    if (mc!=c2) {
        cout << "YES\n";
        for (int i : ret) cout << i << "\n";
    }
    else cout << "NO\n";



    return 0;
}
