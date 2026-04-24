#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int N, M;
int S, mS;

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        string s; int k; cin >> s >> k;
        int as=0, psm=0;
        for (char c : s) {
            as+=(c=='F')-(c=='M');
            psm=max(psm, as);
        }
        mS=max(mS, S+psm);
        mS=max(mS, S+as*(k-1)+psm);
        S+=as*k;
    }
    cout << (S<0?-1:max(0LL, mS-S-1));

    return 0;
}
