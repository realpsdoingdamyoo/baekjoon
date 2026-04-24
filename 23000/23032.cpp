#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, A[2020], d=inf, ans;

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<N; i++) {
        int j=i, k=i+1, l=A[i], r=A[i+1];
        while (1<=j && k<=N) {
            int m=abs(l-r);
            if (d==m) ans=max(ans, l+r);
            if (d>m) d=m, ans=l+r;

            if (l<r) l+=A[--j]; else r+=A[++k];
        }
    }
    cout << ans;

    return 0;
}
