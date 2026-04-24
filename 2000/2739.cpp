#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

signed main() {
    fastio;

    int N; cin >> N;
    for (int i=1; i<=9; i++) cout << N << " * " << i << " = " << N*i << "\n";

    return 0;
}
