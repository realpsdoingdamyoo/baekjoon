#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, A, B;
int X[303030], Y[303030];
vector<int> lnk[303030], rlnk[303030];
int C, E[303030], L[303030], R[303030], V[303030];
int S, SP[303030], EP[303030], PS[303030];

signed main() {
    fastio;

    cin >> N >> M >> A >> B;
    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i];
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back(b), rlnk[b].push_back(a);
        if (c==2) lnk[b].push_back(a), rlnk[a].push_back(b);
    }

    vector<array<int, 2>> vec;
    for (int i=1; i<=N; i++) if (X[i]==A) vec.push_back({Y[i], i}); else E[i]=-1;
    sort(vec.begin(), vec.end());
    for (array<int, 2> i : vec) E[i[1]]=++C, EP[C]=i[1];

    for (int i=1; i<=N; i++) if (X[i]==0) SP[++S]=i;
    sort(SP+1, SP+S+1, [&](int a, int b){return Y[a]<Y[b];});

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq1;
    fill(V+1, V+N+1, 0); fill(L+1, L+N+1, inf);
    for (int i=1; i<=N; i++) if (E[i]>0) pq1.push({E[i], i}), L[i]=E[i];
    while (pq1.size()) {
        int p=pq1.top()[1]; pq1.pop();
        if (V[p]++) continue;
        for (int i : rlnk[p]) L[i]=min(L[i], L[p]), pq1.push({L[i], i});
    }

    priority_queue<array<int, 2>> pq2;
    fill(V+1, V+N+1, 0); fill(R+1, R+N+1, 0);
    for (int i=1; i<=N; i++) if (E[i]>0) pq2.push({E[i], i}), R[i]=E[i];
    while (pq2.size()) {
        int p=pq2.top()[1]; pq2.pop();
        if (V[p]++) continue;
        for (int i : rlnk[p]) R[i]=max(R[i], R[p]), pq2.push({R[i], i});
    }

    vector<int> st;
    fill(V+1, V+N+1, 0);
    for (int i=1; i<=S; i++) st.push_back(SP[i]), V[SP[i]]=1;
    while (st.size()) {
        int p=st.back(); st.pop_back();
        for (int i : lnk[p]) if (!V[i]) V[i]=1, st.push_back(i);
    }

    for (int i=1; i<=C; i++) PS[i]=PS[i-1]+V[EP[i]];
    for (int i=S; i>=1; i--) {
        if (L[SP[i]]==inf) cout << "0\n";
        else cout << (PS[R[SP[i]]]-PS[L[SP[i]]-1]) << "\n";
    }

    return 0;
}
