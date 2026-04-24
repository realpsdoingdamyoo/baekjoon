#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int F[20]={0, 3, 7, 11, 19, 37, 67, 131, 283, 515, 1033, 2053, 4105, 8219};

int N, M, q;

int mul(int x, int y) {
    int r=1;
    for (int i=0; i<=13; i++) if (x&1<<i) r^=y<<i;
    for (int i=13; i>=0; i--) if ((r^(F[q]<<i))<r) r^=F[q]<<i;
    return r;
}

signed main() {
    fastio;

    cin >> N;
    M=(int)sqrt(N/2);
    while (1<<(2*q+1)<N) q++;

    cout << M << "\n";
    for (int i=0; i<M; i++) cout << (i<<q)+mul(mul(i, i), i) << " ";

    return 0;
}
