#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
#define m (s+e>>1)

int N, M, ans, A[202020], B[202020];

vector<int> seg[1010101];
void push(int p, int s, int e, int x, int y) {
    seg[p].push_back(y);
    if (s<e) {if (x<=m) push(p<<1, s, m, x, y); else push(p<<1|1, m+1, e, x, y);}
}

int in(vector<int>& v, int s, int e){return lower_bound(v.begin(), v.end(), s)!=upper_bound(v.begin(), v.end(), e);}
int Find(int p, int s, int e, int l, int r) {
    if (s==e) return s;
    if (in(seg[p<<1|1], l, r)) return Find(p<<1|1, m+1, e, l, r);
    return Find(p<<1, s, m, l, r);
}
int cou(int p, int s, int e, int l, int r, int x) {
    if (r<s || e<l) return 0;
    if (l<=s && e<=r) return seg[p].end()-lower_bound(seg[p].begin(), seg[p].end(), x);
    return cou(p<<1, s, m, l, r, x)+cou(p<<1|1, m+1, e, l, r, x);
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i];
    for (int i=1, x; i<=M; i++) cin >> x, push(1, 1, M, i, x);
    for (int i=1; i<=4*M; i++) sort(seg[i].begin(), seg[i].end());

    for (int i=1; i<=N; i++) {
        int lef=0, fl=(A[i]<B[i]);
        if (A[i]<B[i]) swap(A[i], B[i]);

        if (!in(seg[1], B[i], A[i]-1)) lef=1;
        else lef=Find(1, 1, M, B[i], A[i]-1)+1, fl=0;
        fl+=cou(1, 1, M, lef, M, A[i]);

        if (fl%2) ans+=B[i]; else ans+=A[i];
    }
    cout << ans;

    return 0;
}
