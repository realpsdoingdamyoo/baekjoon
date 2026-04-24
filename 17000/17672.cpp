#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

const int X=1010101;

int N, M, R;
int A[X], B[X], S[X], T[X], P[X], Q[X];
vector<array<int, 2>> F[X];
map<int, int> DP;

void add(int id, int v) {
    for (auto i=DP.lower_bound(id); v<0; i=DP.erase(i))
        id=i->first, v+=i->second;
    DP[id]+=v;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> A[i] >> S[i] >> P[i], A[i]+=A[i-1];
    for (int i=1; i<=M; i++) cin >> B[i] >> T[i] >> Q[i], B[i]+=B[i-1];
    for (int i=1; i<=N; i++) if (S[i]>=A[i]) {
        int j=upper_bound(B+1, B+M+1, S[i]-A[i])-B;
        R+=P[i]; if (j<=M) F[i].push_back({j, -P[i]});
    }
    for (int j=1; j<=M; j++) if (T[j]>=B[j]) {
        int i=upper_bound(A+1, A+N+1, T[j]-B[j])-A;
        if (i<=N) F[i].push_back({j, Q[j]}); else R+=Q[j];
    }
    DP[M+1]=inf;
    for (int i=1; i<=N; i++) {
        sort(F[i].begin(), F[i].end(), [&](array<int, 2> a, array<int, 2> b){return a[1]>b[1];});
        for (array<int, 2> j : F[i]) add(j[0], j[1]);
    }
    for (pair<int, int> i : DP) if (i.first<=M) R+=i.second;
    cout << R;

    return 0;
}
