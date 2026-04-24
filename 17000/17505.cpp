#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, K, A[323232];

signed main(){
    fastio;

    cin >> N >> K;
    for (int i=N, l=1, r=N; i>=1; i--)
        if (K>=i-1) A[l++]=i, K-=i-1; else A[r--]=i;
    for (int i=1; i<=N; i++) cout << A[i] << " ";

    return 0;
}
