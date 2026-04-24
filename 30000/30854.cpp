#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int M, N, R;
int V[101010];
vector<array<int, 3>> X;

signed main() {
    fastio;

    cin >> M >> N;
    for (int i=1; i<=M; i++) cin >> V[i]; V[M]=-1;
    for (int i=1; i<=M; i+=2) X.push_back({V[i], min(V[i-1], V[i+1]), -(V[i-1]>V[i+1])});
    for (int i=1; i<=N; i++) {
        int a, b; cin >> a >> b; X.push_back({a, b, 1});
    }
    sort(X.begin(), X.end(), [&](array<int, 3> a, array<int, 3> b) {
        if (a[0]!=b[0]) return a<b;
        if ((a[2]==1)==(b[2]==1)) return a<b;
        if (a[2]==1) return b[2]==-1; return a[2]!=-1;
    });

    multiset<int> hei; hei.insert(-1);
    vector<array<int, 2>> st;
    for (array<int, 3> i : X) {
        int x=i[1];
        if (i[2]==1) {
            st.push_back({x, 1});
            hei.insert(x);
            continue;
        }

        int err=0;
        while (*prev(hei.end())>x) {
            int mxh=0, er=0;
            while (st.size()) {
                array<int, 2> p=st.back();
                if (p[1]!=1) {
                    if (p[0]<mxh) break;
                    st.pop_back();
                }
                else {
                    mxh=max(mxh, p[0]);
                    hei.erase(hei.find(p[0]));
                    st.pop_back(); er=1;
                }
            }
            R+=er; err+=er;
        }
        if (!err) st.push_back({x, 0});
    }
    cout << R << "\n";

    return 0;
}
