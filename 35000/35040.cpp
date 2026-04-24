#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;
 
int N, M;
priority_queue<int> A, B;
 
void solve() {
    cin >> N >> M;
    while (A.size()) A.pop(); while (B.size()) B.pop();
    for (int i=1, x; i<=N; i++) cin >> x, A.push(x);
    for (int i=1, x; i<=M; i++) cin >> x, B.push(x);
    for (int i=0;; i^=1) {
        if (A.size()==0) {
            cout << (i?"Alice\n":"Bob\n");
            return;
        }
        int x=B.top(); B.pop(); x-=A.top();
        if (x>0) B.push(x);
        swap(A, B);
    }
}
 
signed main() {
    fastio;
 
    int T; cin >> T;
    while (T--) solve();
 
    return 0;
}
