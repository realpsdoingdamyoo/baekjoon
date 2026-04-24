#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, A;
array<int, 2> V[101010];
int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1];
    for (int i=2; i<N; i++) A+=ccw(V[1], V[i], V[i+1]);
    A=abs(A);
    cout << A/2 << "." << A*5%10;

    return 0;
}
