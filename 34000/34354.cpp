#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int T, N;
int V[505050];
int C[505050];

signed main(){
    fastio;

    cin >> T >> N;
    for (int i=1; i<=N; i++) cin >> V[i], C[V[i]]++;
    int X=0;
    for (int i=0; i<T; i++) X+=(C[i]>=2);

    int j=0;
    while (X) {
        j++;
        if (C[V[j]]==2) X--;
        C[V[j]]--;
    }

    array<int, 2> ans={0, j-1};

    for (int i=1; i<=N; i++) {
        C[V[i]]++;
        if (C[V[i]]==2) X++;

        while (j<=N && X) {
            j++;
            if (C[V[j]]==2) X--;
            C[V[j]]--;
        }

        if (j<=N && j-1-i<ans[1]-ans[0]) ans={i, j-1};
    }
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}
