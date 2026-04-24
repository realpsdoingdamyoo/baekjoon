#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int ip[6060];

signed main() {
    fastio;

    for (int i=2; i<=6000; i++) if (!ip[i]) for (int j=i*2; j<=6000; j+=i) ip[j]=1;

    int T; cin >> T;
    while (T--) {
        int N, p; cin >> N;
        p=N+1; while (ip[p]) p++;
        for (int s=1; s<=p; s++) {
            int fl=0; map<int, int> mp;
            for (int i=1; i<=N; i++) {
                int X=2*(p-1)+(i*(i+1)*s)%p-(i*(i-1)*s)%p;
                if (X>3*(N+6) || mp[X]++) {fl=1; break;}
            }
            if (fl) continue;
            for (int i=1; i<=N; i++) cout << 2*(p-1)+(i*(i+1)*s)%p-(i*(i-1)*s)%p << " ";
            cout << "\n"; break;
        }
    }

    return 0;
}
