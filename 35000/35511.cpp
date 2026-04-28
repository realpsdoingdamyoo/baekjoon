#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const long long mod=998244353, inf=4e18;

int N, M, A[303030], B[303030];
vector<array<int, 2>> lnk[303030];

vector<array<int, 2>> DP[303030];
bool bin(int K) {
    for (int i=1; i<=N; i++) DP[i].clear();
    DP[1]={{0, 0}};

    for (int i=2; i<=N; i++) {
        vector<array<int, 2>> dp;
        for (array<int, 2> j : lnk[i]) {
            int p=j[0], x=j[1];
            if (x>K+20) continue;

            for (array<int, 2> d : DP[p]) {
                if (x<K) dp.push_back({d[0]+1, d[1]});
                else dp.push_back({d[0]+1, d[1]|(1<<(x-K))});
            }
        }
        sort(dp.begin(), dp.end(), [&](array<int, 2> a, array<int, 2> b){return a[0]*mod-a[1]<b[0]*mod-b[1];});
        for (array<int, 2> j : dp) {
            while (DP[i].size() && DP[i].back()[1]>=j[1]) DP[i].pop_back();
            DP[i].push_back(j);
        }
    }
    for (array<int, 2> i : DP[N])
        if (i[0]>i[1]) return true;
    return false;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) cin >> A[i] >> B[i], lnk[B[i]].push_back({A[i], i});

    int s=1, e=M;
    while (s<=e) {
        int m=s+e>>1;
        if (bin(m)) e=m-1;
        else s=m+1;
    }
    cout << s-1 << "\n";

    return 0;
}
