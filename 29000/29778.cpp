#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, K, C[252525], S[252525];

struct PST {
    struct node {int C, V, L, R;} nd[5050505];
    vector<int> cmp;
    int pv, rt[252525];

    void update(int n, int p, int s, int e, int x) {
        nd[n]=nd[p]; nd[n].C++; nd[n].V+=cmp[x];
        if (s==e) return;
        int m=s+e>>1;
        if (x<=m) {
            nd[n].L=++pv; nd[n].R=nd[p].R;
            update(nd[n].L, nd[p].L, s, m, x);
        }
        else {
            nd[n].L=nd[p].L; nd[n].R=++pv;
            update(nd[n].R, nd[p].R, m+1, e, x);
        }
    }

    int query(int n, int p, int s, int e, int x) {
        if (s==e) return cmp[s]*x;
        int m=s+e>>1, rc=nd[nd[n].R].C-nd[nd[p].R].C;
        if (rc>=x) return query(nd[n].R, nd[p].R, m+1, e, x);
        return query(nd[n].L, nd[p].L, s, m, x-rc)+(nd[nd[n].R].V-nd[nd[p].R].V);
    }

    int kth(int n, int p, int s, int e, int x) {
        if (s==e) return cmp[s];
        int m=s+e>>1, rc=nd[nd[n].R].C-nd[nd[p].R].C;
        if (rc>=x) return kth(nd[n].R, nd[p].R, m+1, e, x);
        return kth(nd[n].L, nd[p].L, s, m, x-rc);
    }
} pst;

int cost(int l, int r) {
    if (r-l+1<K) return -inf;
    return pst.query(pst.rt[r], pst.rt[l-1], 0, N, K)-(C[r]-C[l-1]);
}

int op[252525], ans=-inf;

void dnc(int s, int e, int l, int r) {
    if (s>e) return;
    int m=s+e>>1;
    op[m]=r; int c=cost(m, r);
    for (int i=r; i>=max(m+K-1, l); i--) {
        int tc=cost(m, i);
        if (tc>c) c=tc, op[m]=i;
    }
    ans=max(ans, c);
    dnc(s, m-1, l, op[m]); dnc(m+1, e, op[m], r);
}

const int X=18;
struct seg2 {
    int seg[1<<X+1];
    void update(int s, int e, int x) {
        s+=1<<X; e+=1<<X;
        while (s<=e) {
            if (s&1) seg[s]=min(seg[s], x); ++s>>=1;
            if (~e&1) seg[e]=min(seg[e], x); --e>>=1;
        }
    }
    int mnv(int p) {
        int r=inf; p+=1<<X;
        while (p) r=min(r, seg[p]), p>>=1;
        return r;
    }
} T;

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> C[i], C[i]+=C[i-1];
    for (int i=1; i<=N; i++) cin >> S[i];

    for (int i=1; i<=N; i++) pst.cmp.push_back(S[i]), pst.rt[i]=++pst.pv;
    sort(pst.cmp.begin(), pst.cmp.end());
    for (int i=1; i<=N; i++) pst.update(i, i-1, 0, N, lower_bound(pst.cmp.begin(), pst.cmp.end(), S[i])-pst.cmp.begin());
    dnc(1, N-K+1, K, N);

    cout << ans << "\n";

    fill(T.seg+1, T.seg+(2<<18), inf);

    for (int i=1, j=K; i<=N-K+1; i++) if (cost(i, op[i])==ans) {
        for (;j<=op[i]; j++) if (cost(i, j)==ans) {
            int th=pst.kth(pst.rt[j], pst.rt[i-1], 0, N, K);
            T.update(i, j, th);
        }
        j--;
    }

    for (int i=1; i<=N; i++) cout << (T.mnv(i)<=S[i]);


    return 0;
}
