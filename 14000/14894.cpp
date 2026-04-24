#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
#define m (s+e>>1)

int N, A[505050], ans;
vector<int> seg[2020202];
void push(int p, int s, int e, int x, int y) {
    seg[p].push_back(y);
    if (s<e){if (x<=m) push(p<<1, s, m, x, y); else push(p<<1|1, m+1, e, x, y);}
}
int cnt(vector<int>& v, int l, int r){return upper_bound(v.begin(), v.end(), r)-lower_bound(v.begin(), v.end(), l);}
int Find(int p, int s, int e, int l, int r, int k) {
    if (s==e) return seg[p][0];
    int lc=cnt(seg[p<<1], l, r);
    if (k<=lc) return Find(p<<1, s, m, l, r, k);
    return Find(p<<1|1, m+1, e, l, r, k-lc);
}

void solve(int s, int e) {
    if (s>=e) return;
    ans+=e-s+1;
    int x=Find(1, 1, N, s, e, (e-s)/2+1);
    if (x<s || e<x) return;
    solve(s, x-1); solve(x+1, e);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i], push(1, 1, N, i, A[i]);
    for (int i=1; i<=4*N; i++) sort(seg[i].begin(), seg[i].end());
    solve(1, N);
    cout << ans;

    return 0;
}
