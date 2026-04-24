#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

const int MX=505050;
#define m (s+e>>1)

int N, K;
array<int, 3> V[101010];
multiset<int> st[101010];
vector<array<int, 2>> up[MX];

int seg[MX*4], lzy[MX*4];
void update(int p, int s, int e, int l, int r, int x) {
    if (r<s || e<l) return;
    if (l<=s && e<=r) {lzy[p]+=x; return;}
    update(p<<1, s, m, l, r, x); update(p<<1|1, m+1, e, l, r, x);
    seg[p]=max(seg[p<<1]+lzy[p<<1], seg[p<<1|1]+lzy[p<<1|1]);
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) for (int& j : V[i]) cin >> j;
    sort(V+1, V+N+1);
    for (int i=1; i<=K; i++) st[i].insert(-MX), st[i].insert(MX);

    int s=0, e=252525;
    while (s<=e) {
        int D=s+e>>1, fl=0;

        for (int i=1; i<MX; i++) up[i].clear();

        for (int i=1; i<=N; i++) {
            up[V[i][0]].push_back({V[i][1], V[i][2]});
            up[V[i][0]+D+1].push_back({V[i][1], -V[i][2]});
        }

        for (int i=1; i<MX; i++) {
            for (array<int, 2> j : up[i]) {
                int p=j[0], c=j[1];

                if (c>0) {
                    st[c].insert(p);
                    int l=max(*prev(st[c].find(p))+D+1, p);
                    int r=min(*next(st[c].find(p))-1, p+D);
                    update(1, 1, MX, l, r, 1);
                }
                else {
                    int l=max(*prev(st[-c].find(p))+D+1, p);
                    int r=min(*next(st[-c].find(p))-1, p+D);
                    st[-c].erase(st[-c].find(p));
                    update(1, 1, MX, l, r, -1);
                }
            }
            if (seg[1]==K) fl=1;
        }

        if (!fl) s=D+1; else e=D-1;
    }

    cout << s;


    return 0;
}
