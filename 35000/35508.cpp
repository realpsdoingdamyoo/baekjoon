#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N, D;
array<int, 3> V[202020];

signed main() {
    fastio;

    cin >> N >> D;
    for (int i=1; i<=N; i++) cin >> V[i][2] >> V[i][0] >> V[i][1];

    map<int, int> MA;
    vector<int> A={0};
    sort(V+1, V+N+1, [&](array<int, 3> a, array<int, 3> b){return a[2]<b[2];});
    for (int i=1; i<=N; i++) {
        if (A.size()==0 || MA[A.back()]<V[i][0]) {
            A.push_back(V[i][2]); MA[V[i][2]]=max(MA[V[i][2]], V[i][0]);
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        if (V[i][2]<=D) {
            ans=max(ans, V[i][0]+V[i][1]);
            int lf=D-V[i][2];
            int p=*prev(upper_bound(A.begin(), A.end(), lf));
            ans=max(ans, V[i][1]+MA[p]);
        }
    }
    cout << ans;



    return 0;
}
