#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

const int X=150000;
int N, C, S, g, A[20202];
bitset<X> BL, BR;
void solve() {
    cin >> N >> C; S=g=0;
    for (int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);

    BL.reset(); BL.set(0, 1); BR.reset(); BR.set(0, 1);
    for (int i=N; i>=1; i--) {
        if (S+A[i]<C) S+=A[i], BR|=BR<<A[i];
        else BL|=BL<<A[i];
    }

    set<int> st={inf};
    for (int i=0; i<X; i++) if (BR[i]) st.insert(i);
    for (int i=0; i<X; i++) if (BL[i]) g=max(g, S+i-*st.lower_bound(S+i-C));
    cout << g << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
