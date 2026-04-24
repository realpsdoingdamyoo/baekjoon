#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, K, A[202020];
vector<int> lnk[202020];

int S[202020], C[202020], T[202020], X[202020], D[202020];
void dfs(int p) {
    vector<array<int, 3>> vec;
    S[p]=A[p];
    for (int i : lnk[p]) {
        dfs(i), vec.push_back({T[i]+2, S[i], i});
        S[p]+=S[i], C[p]+=C[i]+S[i], T[p]+=T[i]+2; D[p]=max(D[p], D[i]+1);
    }
    sort(vec.begin(), vec.end(), [&](array<int, 3> a, array<int, 3> b){return a[0]*b[1]<a[1]*b[0];});
    int s=0; for (array<int, 3> i : vec) C[p]+=i[1]*s, s+=i[0];

    if (K==1 && lnk[p].size()) {
        reverse(vec.begin(), vec.end());
        int ts=0, ss=0; X[p]=inf;
        for (array<int, 3> i : vec) {
            if (D[i[2]]+1==D[p]) X[p]=min(X[p], C[p]+ts*i[1]-ss*i[0]+(X[i[2]]-C[i[2]]));
            ts+=i[0]; ss+=i[1];
        }
    }
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=2, x; i<=N; i++) cin >> x >> A[i], lnk[x].push_back(i);
    dfs(1);

    if (K) cout << T[1]-D[1] << " " << X[1];
    else cout << T[1] << " " << C[1];

    return 0;
}
