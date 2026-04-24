#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
#define m (s+e>>1)

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

int N, K, rt=1, MX=4e9;
array<int, 2> V[252525];

int seg[50505050], L[50505050], R[50505050], pv=1;

void update(int& p, int s, int e, int x, int y) {
    if (p==0) p=++pv; seg[p]+=y;
    if (s==e) return;
    if (x<=m) update(L[p], s, m, x, y); else update(R[p], m+1, e, x, y);
}
int sum(int p, int s, int e, int l, int r) {
    if (p==0 || e<l || r<s) return 0;
    if (l<=s && e<=r) return seg[p];
    return sum(L[p], s, m, l, r)+sum(R[p], m+1, e, l, r);
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> V[i][0] >> V[i][1];
        V[i]={V[i][0]+V[i][1], V[i][0]-V[i][1]};
    }
    sort(V+1, V+N+1);

    int s=1, e=MX;
    while (s<=e) {
        int D=s+e>>1, cnt=0, i, j=1;

        for (i=1; i<=N; i++) {
            while (V[j][0]<V[i][0]-D) update(rt, -MX, MX, V[j][1], -1), j++;
            cnt+=sum(rt, -MX, MX, V[i][1]-D, V[i][1]+D);
            update(rt, -MX, MX, V[i][1], 1);
            if (cnt>=K) break;
        }
        i=min(i, N);
        while (j<=i) update(rt, -MX, MX, V[j][1], -1), j++;

        if (cnt>=K) e=D-1; else s=D+1;
    }

    vector<int> ans;

    set<array<int, 2>> st;
    for (int i=1, j=1; i<=N; i++) {
        while (V[j][0]<V[i][0]-e) st.erase(st.find({V[j][1], j})), j++;
        set<array<int, 2>>::iterator it=st.lower_bound({V[i][1]-e, -inf});
        while (it!=st.end() && (*it)[0]<=V[i][1]+e) {
            int p=(*it)[1];
            ans.push_back(max(abs(V[i][0]-V[p][0]), abs(V[i][1]-V[p][1])));
            it=next(it);
        }
        st.insert({V[i][1], i});
    }

    sort(ans.begin(), ans.end());
    while (ans.size()<K) ans.push_back(s);
    for (int i : ans) cout << i << "\n";

    return 0;
}
