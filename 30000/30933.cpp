#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q;
int R[505050], C[505050], RA, CA;

signed main() {
    fastio;

    cin >> N >> Q; RA=CA=N;
    for (int i=1; i<=N; i++) R[i]=C[i]=i%2;

    for (int i=1; i<=Q; i++) {
        string s; int a;
        cin >> s >> a;
        if (s=="ROW") {
            if (a!=1) RA-=(R[a]^R[a-1]);
            if (a!=N) RA-=(R[a]^R[a+1]);
            R[a]^=1;
            if (a!=1) RA+=(R[a]^R[a-1]);
            if (a!=N) RA+=(R[a]^R[a+1]);
        }
        else {
            if (a!=1) CA-=(C[a]^C[a-1]);
            if (a!=N) CA-=(C[a]^C[a+1]);
            C[a]^=1;
            if (a!=1) CA+=(C[a]^C[a-1]);
            if (a!=N) CA+=(C[a]^C[a+1]);
        }
        cout << RA*CA << "\n";
    }

    return 0;
}
