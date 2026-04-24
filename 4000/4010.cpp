#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, C, D;
int X[1515], Y[1515];
const double pi=3.141592653589793238;

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i];

    for (int i=1; i<=N; i++) {
        vector<double> vec;

        for (int j=1; j<=N; j++) if (i!=j) {
            double a=atan2(Y[j]-Y[i], X[j]-X[i]);
            if (a<0) a+=pi*2;
            vec.push_back(a);
        }

        sort(vec.begin(), vec.end());

        int M=N-1, p=0;
        for (int j=0; j<M; j++) {
            while ((p+1)%M!=j) {
                int q=(p+1)%M;
                double x=vec[q]-vec[j];
                if (x<0) x+=pi*2;
                if (x<pi) p++;
                else break;
            }
            int K=(p-j+M)%M;
            C+=K*(K-1)/2;
        }
    }

    int R=N*(N-1)*(N-2)*(N-3)/6;
    int T=R-C, Q=R/4-T;

    cout << 3+(T+2*Q+0.0)/(R/(N-3));

    return 0;
}
