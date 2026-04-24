#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, M, A[101010];

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<N; i++) M+=(A[i]>A[i+1]);
    cout << (N%2==1 && M?"Alice":"Bob");

    return 0;
}
