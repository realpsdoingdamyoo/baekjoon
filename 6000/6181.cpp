#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, d, ans1, ans2=1;
array<int, 2> v[101010];
array<int, 4> X[202020];
set<array<int, 2>> st;

int g[101010];
int Find(int x){return g[x]<0?x:g[x]=Find(g[x]);}
void Union(int a, int b) {a=Find(a); b=Find(b); g[a]+=g[b]; g[b]=a;}

signed main() {
    fastio;

    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0] >> v[i][1];
        X[i*2-1]={v[i][0]+v[i][1], 0, v[i][0]-v[i][1], i};
        X[i*2]={v[i][0]+v[i][1]+d, 1, v[i][0]-v[i][1], i};
    }
    sort(X+1, X+n*2+1);

    for (int i=1; i<=n; i++) g[i]=-1;

    for (int i=1; i<=2*n; i++) {
        int io=X[i][1], y=X[i][2], p=X[i][3];
        if (io==0) {
            if (st.lower_bound({y-d, -inf})!=st.upper_bound({y, inf})) {
                int q=(*st.lower_bound({y-d, -inf}))[1];
                if (Find(p)!=Find(q)) Union(p, q), ans1--, ans2=max(ans2, -g[Find(p)]);
            }
            if (st.lower_bound({y+1, -inf})!=st.upper_bound({y+d, inf})) {
                int q=(*st.lower_bound({y+1, -inf}))[1];
                if (Find(p)!=Find(q)) Union(p, q), ans1--, ans2=max(ans2, -g[Find(p)]);
            }
            st.insert({y, p});
        }
        else st.erase(st.find({y, p}));
    }
    cout << n+ans1 << " " << ans2;

    return 0;
}
