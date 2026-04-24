#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, X;
int A[303030], B[303030];

array<int, 2> trie[10101010];
int pv=1;

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i], X^=A[i];
    for (int i=1; i<=N; i++) cin >> B[i], X^=B[i];

    for (int i=1; i<=N; i++) {
        int p=1;
        for (int j=30; j>=0; j--) {
            int x=!!(B[i]&(1<<j));
            if (trie[p][x]==0) p=trie[p][x]=++pv;
            else p=trie[p][x];
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        int p=1, r=0;
        for (int j=30; j>=0; j--) {
            int x=!!((A[i]^X)&(1<<j));
            if (trie[p][x]!=0) p=trie[p][x];
            else r|=1<<j, p=trie[p][x^1];
        }
        ans=max(ans, r);
    }

    cout << ans;

    return 0;
}
