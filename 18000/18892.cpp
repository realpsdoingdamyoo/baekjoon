#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

const int X=17;
array<int, 2> seg[1<<X+1];
array<int, 2> mrg(array<int, 2> a, array<int, 2> b){return {max(a[0], b[0]), min(inf, (a[0]>=b[0])*a[1]+(a[0]<=b[0])*b[1])};}

void update(int p, array<int, 2> x) {
    p+=1<<X; seg[p]=x; p>>=1;
    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}

array<int, 2> Mrg(int s, int e) {
    array<int, 2> ret={0, 0}; s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) ret=mrg(ret, seg[s]); ++s>>=1;
        if (~e&1) ret=mrg(ret, seg[e]); --e>>=1;
    }
    return ret;
}

int n, k, p;
int v[101010], r[101010], wy[101010];
vector<int> lis[101010];

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {cin >> v[i]; r[v[i]]=i;}
    for (int i=n; i>=1; i--) {
        array<int, 2> gt=Mrg(v[i]+1, n);
        gt[0]+=1; gt=mrg(gt, {1, 1});
        update(v[i], gt); wy[i]=gt[1];
        lis[gt[0]].push_back(i);
    }
    if (seg[1][1]<k) {cout << "-1"; return 0;}

    for (int i=1; i<=n; i++) {
        if (lis[i].size()) p=i; else break;
        sort(lis[i].begin(), lis[i].end(), [&](int a, int b){return v[a]<v[b];});
    }

    int s=0;
    for (int l=p; l>=1; l--) {
        for (int i : lis[l]) if (s<i && v[s]<v[i]) {
            if (k>wy[i]) k-=wy[i];
            else {cout << v[i] << " "; s=i; break;}
        }
    }

    return 0;
}
