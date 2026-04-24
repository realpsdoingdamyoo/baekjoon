#include <bits/stdc++.h>
using namespace std;

long long N, A[202020], B[202020];
signed main() {
    cin >> N;
    for (int i=1; i<N; i++) cin >> A[i];
    A[0]=A[N]=(1LL<<60)-1; B[0]=B[N+1]=(1LL<<60)-1;
    for (int i=1; i<=N; i++) B[i]=A[i-1]&A[i];
    for (int j=59; j>=0; j--) for (int i=1; i<=N; i++) {
        int x=B[i-1]>>j, y=B[i]>>j, z=B[i+1]>>j;
        if ((x<y || i==1) && y==z && A[i-1]&B[i-1]&B[i]&A[i]&B[i+1]&1LL<<j) B[i]^=1LL<<j;
    }
    for (int i=1; i<N; i++) if (B[i]>B[i+1] || A[i]!=(B[i]|B[i+1])){cout << "No"; return 0;}
    cout << "Yes\n"; for (int i=1; i<=N; i++) cout << B[i] << " ";
}
