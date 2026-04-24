#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
#define m (s+e>>1)

int N, M, W, H;
vector<array<int, 3>> vec;

const int MX=2e9, SZ=20202020;

array<int, 2> seg[SZ];
int lzy[SZ], L[SZ], R[SZ], pv;

int get(int& x, int s, int e) {if (x==0) x=++pv, seg[x]={0, e}; return x;}
array<int, 2> add(array<int, 2> a, int x) {a[0]+=x; return a;}

void update(int p, int s, int e, int l, int r, int x) {
    if (r<s || e<l) return;
    if (l<=s && e<=r) {lzy[p]+=x; return;}
    update(get(L[p], s, m), s, m, l, r, x); update(get(R[p], m+1, e), m+1, e, l, r, x);
    seg[p]=max(add(seg[L[p]], lzy[L[p]]), add(seg[R[p]], lzy[R[p]]));
}

signed main() {
    fastio;

    cin >> N >> M >> W >> H;
    for (int i=1, x, y; i<=N; i++) cin >> x >> y, vec.push_back({x, y, -1});
    for (int i=1, x, y; i<=M; i++) cin >> x >> y, vec.push_back({x, y, 1});
    for (int i=0; i<N+M; i++) vec.push_back({vec[i][0]+W, 0, 0});
    sort(vec.begin(), vec.end());

    array<int, 3> ans={0, mod, mod};

    seg[1]={0, MX}; lzy[1]=L[1]=R[1]=0; pv=1;
    for (int i=0, l=0, r=0; i<vec.size(); i=r) {
        while (r<vec.size() && vec[r][0]==vec[i][0]) update(1, -MX, MX, vec[r][1], vec[r][1]+H, vec[r][2]), r++;
        while (l<vec.size() && vec[l][0]+W<vec[i][0]) update(1, -MX, MX, vec[l][1], vec[l][1]+H, -vec[l][2]), l++;
        ans=max(ans, {seg[1][0]+lzy[1], vec[i][0]-W, seg[1][1]-H});
    }

    seg[1]={0, MX}; lzy[1]=L[1]=R[1]=0;
    for (int i=0, l=0, r=0; i<vec.size(); i=r) {
        while (r<vec.size() && vec[r][0]==vec[i][0]) update(1, -MX, MX, vec[r][1], vec[r][1]+H, -vec[r][2]), r++;
        while (l<vec.size() && vec[l][0]+W<vec[i][0]) update(1, -MX, MX, vec[l][1], vec[l][1]+H, vec[l][2]), l++;
        ans=max(ans, {seg[1][0]+lzy[1], vec[i][0]-W, seg[1][1]-H});
    }

    cout << ans[0] << "\n" << ans[1] << " " << ans[2];

    return 0;
}
