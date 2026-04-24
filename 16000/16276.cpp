#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, A[110], imp[1010101];

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i=1; i<=N; i++) cin >> A[i];
        for (int i=1; i<=1000000; i++) imp[i]=0;
        cout << "YES\n";

        for (int i=1, p=1; i<=N; i++) {
            while (imp[p]) p++;
            cout << p << " ";

            for (int j=1; j<=N; j++) for (int k=1; k<=N; k++) {
                int g=p+A[j]-A[k];
                if (1<=g && g<=1000000) imp[g]=1;
            }
        }
        cout << "\n";
    }

    return 0;
}
