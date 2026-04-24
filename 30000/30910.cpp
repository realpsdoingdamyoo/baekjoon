#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, A[1010101];

void solve() {
    cin >> N;
    int C3=0, L=-1, R=-1, X=0;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        X^=A[i];
        if (A[i]==3) C3++;
        if (A[i]) R=A[i], L=(L==-1?A[i]:L);
    }
    if (C3==0) cout << "0\n";
    else if (C3==N) {
        if (N==1) cout << "-1\n";
        else if (N%2==0) cout << "1\n";
        else cout << "3\n";
    }
    else {
        if (L==3 && R==3 && X==3) cout << "2\n";
        else cout << "1\n";
    }
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
