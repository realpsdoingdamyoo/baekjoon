#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
set<array<int, 2>> st;
array<int, 3> V[101010];
int ans[101010];

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1] >> V[i][2];
    sort(V+1, V+N+1, [&](array<int, 3> a, array<int, 3> b){return a[2]<b[2];});
    st.insert({0, ++K});

    for (int i=1; i<=N; i++) {
        if (V[i][1]<(*st.begin())[0]) st.insert({0, ++K});
        array<int, 2> p=*prev(st.lower_bound({V[i][1]+1, -1}));
        ans[V[i][0]]=p[1]; st.insert({V[i][2], p[1]}); st.erase(st.find(p));
    }

    cout << K << "\n";
    for (int i=1; i<=N; i++) cout << ans[i] << "\n";


    return 0;
}
