#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int al(int p, int q, int t) {
    return p==0 || (t-q+2*p)%(p*2)>=p;
}

bool solve() {
    int N, P[110]={}, Q[110]={}, A[110]={1}, B[110];
    cin >> N; if (!N) return false;
    for (int i=1; i<=N; i++) cin >> P[i];
    for (int i=1; i<=N; i++) cin >> Q[i];

    for (int t=1; t<=20000; t++) {
        for (int i=1; i<=N+1; i++) B[i]=A[i-1]||A[i]||A[i+1];
        for (int i=1; i<=N+1; i++) A[i]=B[i]&&al(P[i], Q[i], t);
        if (A[N+1]) {cout << t << "\n"; return true;}
    }
    cout << "0\n";
    return true;
}

signed main(){
    fastio;

    while (solve()){}

    return 0;
}
