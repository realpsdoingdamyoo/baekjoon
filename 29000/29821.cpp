#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

const int MX=10101010, W=3e9;
int N, X[303030], lzy, ans=0;
int seg[2][MX], L[2][MX], R[2][MX], pv[2]={1, 1};

int get(int& x, int t){return x?x:x=++pv[t];}

void update(int t, int p, int s, int e, int x, int y) {
    if (s==e) {seg[t][p]=min(seg[t][p], y); return;}
    int m=(s+e)/2;
    if (x<=m) update(t, get(L[t][p], t), s, m, x, y); else update(t, get(R[t][p], t), m+1, e, x, y);
    seg[t][p]=min(seg[t][L[t][p]], seg[t][R[t][p]]);
}

int minv(int t, int p, int s, int e, int l, int r) {
    if (e<l || r<s) return inf;
    if (l<=s && e<=r) return seg[t][p];
    int m=(s+e)/2;
    return min(minv(t, get(L[t][p], t), s, m, l, r), minv(t, get(R[t][p], t), m+1, e, l, r));
}

signed main() {
    fastio;

    cin >> N >> X[1] >> X[2];
    for (int i=1; i<=N; i++) cin >> X[i+2];
    for (int i=1; i<=N+2; i++) X[i]+=W/2;
    fill(seg[0], seg[0]+MX, inf); fill(seg[1], seg[1]+MX, inf);

    update(0, 1, 1, W, X[1], -X[1]);
    update(1, 1, 1, W, X[1], X[1]);

    for (int i=3; i<=N+2; i++) {
        int gnv=min(minv(0, 1, 1, W, 1, X[i])+X[i], minv(1, 1, 1, W, X[i], W)-X[i])+lzy;
        lzy+=abs(X[i]-X[i-1]);
        update(0, 1, 1, W, X[i-1], gnv-X[i-1]-lzy);
        update(1, 1, 1, W, X[i-1], gnv+X[i-1]-lzy);
        ans=min(ans, gnv-lzy);
    }

    cout << ans+lzy;

    return 0;
}
