#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, M, K, B, F[101010];
vector<int> V[101010];

int C=0, sv=0;
void get(int p, int x, int t) {
    if (C>=K) return;
    if (p && x<V[p][0]) p=upper_bound(F+1, F+N+1, x)-F-1;
    if (p==0) {sv+=t*(x+1); C++; return;}

    get(p-1, x, t);
    for (int i=0; i<V[p].size() && V[p][i]<=x; i++) get(p-1, x-V[p][i], t);
}

signed main() {
    fastio;

    cin >> M >> K;
    for (int i=1; i<=M; i++) {
        int x; cin >> x;
        vector<int> v(x);
        for (int& j : v) cin >> j;
        sort(v.begin(), v.end());
        B+=v[0];
        for (int j=x-1; j>=0; j--) v[j]-=v[0];
        v.erase(v.begin());
        if (v.size()) V[++N]=v;
    }

    sort(V+1, V+N+1);
    for (int i=1; i<=N; i++) F[i]=V[i][0];

    int s=0, e=1e14;
    while (s<=e) {
        int m=s+e>>1;
        C=0; get(N, m, 0);
        if (C>=K) e=m-1; else s=m+1;
    }
    C=0; if (s) get(N, s-1, 1);
    cout << K*(B+s)-sv;

    return 0;
}
