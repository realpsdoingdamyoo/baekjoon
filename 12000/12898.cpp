#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;
#define m (s+e>>1)

int N, Q, V[101010], U[101010], RV[101010], RU[101010], R[101010];
string S[101010], T[101010];

int nxt(string& p) {
    for (int i=p.length()-1; i>=0; i--) {
        if (p[i]=='Z') p[i]='A';
        else {p[i]++; return 0;}
    }
    return 1;
}

vector<int> seg[404040];
void bui(int p, int s, int e) {
    if (s==e) seg[p].push_back(R[s]);
    else {
        bui(p<<1, s, m); bui(p<<1|1, m+1, e);
        for (int i : seg[p<<1]) seg[p].push_back(i);
        for (int i : seg[p<<1|1]) seg[p].push_back(i);
        sort(seg[p].begin(), seg[p].end());
    }
}

int query(int p, int s, int e, int l, int r, int d, int u) {
    if (r<s || e<l) return 0;
    if (l<=s && e<=r) return upper_bound(seg[p].begin(), seg[p].end(), u)-lower_bound(seg[p].begin(), seg[p].end(), d);
    return query(p<<1, s, m, l, r, d, u)+query(p<<1|1, m+1, e, l, r, d, u);
}

signed main(){
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> S[i], T[i]=S[i], reverse(T[i].begin(), T[i].end());
    for (int i=1; i<=N; i++) V[i]=U[i]=i;
    sort(V+1, V+N+1, [&](int a, int b){return S[a]<S[b];});
    sort(U+1, U+N+1, [&](int a, int b){return T[a]<T[b];});
    for (int i=1; i<=N; i++) RV[V[i]]=i, RU[U[i]]=i;
    for (int i=1; i<=N; i++) R[RV[i]]=RU[i];
    sort(S+1, S+N+1); sort(T+1, T+N+1);
    bui(1, 1, N);

    while (Q--) {
        string A, B; cin >> A >> B;
        reverse(B.begin(), B.end());
        int ls, le=N, rs, re=N;
        ls=lower_bound(S+1, S+N+1, A)-S;
        if (!nxt(A)) le=lower_bound(S+1, S+N+1, A)-S-1;
        rs=lower_bound(T+1, T+N+1, B)-T;
        if (!nxt(B)) re=lower_bound(T+1, T+N+1, B)-T-1;

        cout << query(1, 1, N, ls, le, rs, re) << "\n";
    }

    return 0;
}
