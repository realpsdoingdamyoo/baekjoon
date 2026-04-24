#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int solve(int N) {
    if (N<3) return N;
    int x=1;
    while (x*3<=N) x*=3;
    return (N/x+solve(N%x))%3;
}

signed main(){
    fastio;

    while (1) {
        int N; cin >> N;
        if (!N) break;
        cout << ("PSR")[solve(N-1)] << "\n";
    }

    return 0;
}
