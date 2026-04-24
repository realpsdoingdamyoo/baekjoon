#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

const int MX=101010;
int N, A[MX], l, r, C[MX], ans[MX];
vector<int> V, Am[MX], Dm[MX], Ap[MX], Dp[MX];
void push(vector<int>& V1, vector<int>& V2, int x) {
    V1.push_back(x); V2.push_back(x);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=2; i<=N; i++) cin >> A[i], V.push_back((A[i]-i+N)%N);
    if (N==2) {cout << (A[2]==1?"1\n1":"0\n2"); return 0;}
    sort(V.begin(), V.end());

    for (int i=0; i+1<V.size(); i++) {
        l=V[i]; r=V[i+1];
        push(Am[0], Dm[l+1], 2*l+N-r); push(Ap[0], Dp[l+1], l+2*N-2*r);
        push(Am[r], Dm[N], 2*l+2*N-r); push(Ap[r], Dp[N], l+N-2*r);
        for (int j=l; j<=r; j++) C[j]=max({C[j], j-l, r-j});
    }

    l=V.back(); r=V[0];
    push(Am[r], Dm[l+1], 2*l-r), push(Ap[r], Dp[l+1], l-2*r);
    for (int j=l; j<=r+N; j++) C[j%N]=max({C[j%N], j-l, r+N-j});

    multiset<int> M, P;
    for (int i=0; i<N; i++) {
        for (int j : Am[i]) M.insert(j); for (int j : Dm[i]) M.erase(M.find(j));
        for (int j : Ap[i]) P.insert(j); for (int j : Dp[i]) P.erase(P.find(j));
        cout << min(i, N-i)+min({N-C[i], *M.begin()-i, *P.begin()+i}) << "\n";
    }

    return 0;
}
