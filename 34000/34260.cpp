#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int S=0, C=1;

void ap() {
    int N, M; cin >> N >> M;
    vector<array<int, 2>> vec(M);
    vector<int> pnt(N);
    for (int& i : pnt) cin >> i;
    for (array<int, 2>& i : vec) cin >> i[0] >> i[1];

    int s=0, c=0;
    for (int i=0; i<(1<<N); i++) {
        int x=0;
        for (array<int, 2> j : vec) {
            if (!(i&(1<<j[0]-1)) && (i&(1<<j[1]-1))) x++;
        }
        if (x) continue;
        for (int j=0; j<N; j++) if (i&(1<<j)) s+=pnt[j]; c++;
    }
    S=(S*c+s*C)%MOD; C=C*c%MOD;
}

signed main(){
    fastio;

    int P; cin >> P;
    while (P--) ap();
    cout << S;

    return 0;
}
