#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, A[101010], C[101010], ans;

int pv(int X) {
    while (C[X]) X--;
    return X;
}

int get(int X) {
    int Y=pv(X-1);
    if (Y==0) return -inf;
    int Z=pv(Y-1);
    if (Z==0) return -inf;

    while (Z>0) {
        if (A[X]<A[Y]+A[Z]) return A[X]+A[Y]+A[Z];
        X=Y; Y=Z; Z=pv(Z-1);
    }
    return -inf;
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);

    for (int i=1; i<=N; i++) for (int j=i-1; j>=max(i-5, 1LL); j--) for (int k=j-1; k>=max(j-5, 1LL); k--)
        if (A[i]<A[j]+A[k]) {
        C[i]=C[j]=C[k]=1;
        ans=max(ans, A[i]+A[j]+A[k]+get(pv(i)));
        C[i]=C[j]=C[k]=0;
    }
    cout << ans;

    return 0;
}
