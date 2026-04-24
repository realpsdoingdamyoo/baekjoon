#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
int H[202020], A[202020], B[202020], R[202020];
int Q;
int QL[202020], QR[202020];
vector<int> tg[202020];

int lzy[1010101], on[202020], mn[1010101], hmx[1010101];
void tog(int p, int s, int e, int x) {
    if (s==e) {
        hmx[p]=max(hmx[p], lzy[p]-mn[p]);
        on[x]^=1; lzy[p]=-inf; mn[p]=on[x]?H[x]:inf; return;
    }
    int m=s+e>>1;
    hmx[p]=max(hmx[p], lzy[p]-mn[p]);
    lzy[p<<1]=max(lzy[p<<1], lzy[p]); lzy[p<<1|1]=max(lzy[p<<1|1], lzy[p]); lzy[p]=-inf;
    if (x<=m) tog(p<<1, s, m, x); else tog(p<<1|1, m+1, e, x);
    mn[p]=min(mn[p<<1], mn[p<<1|1]);
    hmx[p]=max({hmx[p<<1], lzy[p<<1]-mn[p<<1], hmx[p<<1|1], lzy[p<<1|1]-mn[p<<1|1]});
}

void update(int p, int s, int e, int l, int r, int x) {
    if (e<l || r<s) return;
    if (l<=s && e<=r) {
        lzy[p]=max(lzy[p], x);
        hmx[p]=max(hmx[p], lzy[p]-mn[p]);
        return;
    }
    int m=s+e>>1;
    update(p<<1, s, m, l, r, x); update(p<<1|1, m+1, e, l, r, x);
    hmx[p]=max({hmx[p<<1], lzy[p<<1]-mn[p<<1], hmx[p<<1|1], lzy[p<<1|1]-mn[p<<1|1]});
}

int query(int p, int s, int e, int l, int r) {
    if (e<l || r<s) return -inf;
    if (l<=s && e<=r) return max(hmx[p], lzy[p]-mn[p]);
    int m=s+e>>1;
    lzy[p<<1]=max(lzy[p<<1], lzy[p]); lzy[p<<1|1]=max(lzy[p<<1|1], lzy[p]);
    return max(query(p<<1, s, m, l, r), query(p<<1|1, m+1, e, l, r));
}

int S[202020];
vector<array<int, 2>> qrs[202020];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> H[i] >> A[i] >> B[i];
    cin >> Q;
    for (int i=1; i<=Q; i++) S[i]=-1;
    for (int i=1; i<=Q; i++) cin >> QL[i] >> QR[i], qrs[QR[i]].push_back({QL[i], i});

    for (int i=1; i<=N; i++) {
        if (i+A[i]<=N) tg[i+A[i]].push_back(i);
        if (i+B[i]+1<=N) tg[i+B[i]+1].push_back(i);
    }

    for (int t=0; t<=1; t++) {
        fill(lzy+1, lzy+N*4+1, -inf);
        fill(on+1, on+N+1, 0);
        fill(mn+1, mn+N*4+1, inf);
        fill(hmx+1, hmx+N*4+1, -inf);
        for (int i=1; i<=N; i++) {
            for (int j : tg[i]) tog(1, 1, N, j);
            if (i-A[i]>=1) update(1, 1, N, max(1LL, i-B[i]), i-A[i], H[i]);
            for (array<int, 2> j : qrs[i]) {
                int xxx=query(1, 1, N, j[0], i);
                S[j[1]]=max(S[j[1]], xxx);
            }
        }
        for (int i=1; i<=N; i++) H[i]=-H[i];
    }

    for (int i=1; i<=Q; i++) cout << S[i] << "\n";


    return 0;
}
