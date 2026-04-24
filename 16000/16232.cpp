#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

const int X=18;
set<array<int, 3>> seg[2<<X];

int N;
int A[202020], B[202020], K[202020];

void merg(set<array<int, 3>>& r, set<array<int, 3>>& a, set<array<int, 3>>& b) {
    if (a.size()==0) {r=b; return;}
    if (b.size()==0) {r=a; return;}
    for (array<int, 3> i : a) {
        int s=i[0], e=i[1], x=i[2];
        while (s<=e) {
            array<int, 3> it=*prev(b.lower_bound({max(s+x, -inf), inf, inf}));
            if (it[1]==inf) it[1]+=x;
            r.insert({s, min(e, it[1]-x), x+it[2]});
            s=min(e, it[1]-x)+1;
        }
    }
}

void pass(int p, int s, int e, int l, int r, int& v) {
    if (e<l || r<s) return;
    if (l<=s && e<=r) {v+=(*prev(seg[p].lower_bound({v, inf, inf})))[2]; return;}
    int m=s+e>>1;
    pass(p<<1, s, m, l, r, v); pass(p<<1|1, m+1, e, l, r, v);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i] >> K[i];
    for (int i=1; i<=N; i++) seg[i+(1<<X)].insert({-inf, K[i]-1, A[i]}), seg[i+(1<<X)].insert({K[i], inf, B[i]});
    for (int i=(1<<X)-1; i>=1; i--) merg(seg[i], seg[i<<1], seg[i<<1|1]);

    for (int i=1; i<=N; i++) {
        int v=0;
        pass(1, 0, (1<<X)-1, 1, i-1, v);
        pass(1, 0, (1<<X)-1, i+1, N, v);
        cout << v << '\n';
    }

    return 0;
}
