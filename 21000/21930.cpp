#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
double A[1010], pi=acos(-1);

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);

    double R=1e7;
    for (double de=1e5; de>1e-10; de*=0.99) {
        if (R<=A[N]) {R+=de; continue;}
        double th=0;
        for (int i=1; i<N; i++) th+=asin(A[i]/R)*2;
        double le=R*sin(th/2);
        if (th>2*pi) R+=de;
        else if (le>A[N]) R-=de; else R+=de;
    }
    cout.precision(14);
    cout << R/2;


    return 0;
}
