#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<int> lnk[101010];
vector<array<int, 2>> edg;
int deg[101010];
vector<int> st;

int O[101010], pv;
int L[101010], R[101010];
int U[101010];

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); deg[b]++;
        edg.push_back({a, b});
    }

    for (int i=1; i<=N; i++) if (!deg[i]) st.push_back(i);

    while (st.size()) {
        int p=st.back(); st.pop_back();
        O[p]=++pv;
        for (int i : lnk[p]) if (!--deg[i]) st.push_back(i);
    }

    for (int i=1; i<=N; i++) L[i]=0, R[i]=N+1;
    for (array<int, 2> i : edg) L[i[1]]=max(L[i[1]], O[i[0]]), R[i[0]]=min(R[i[0]], O[i[1]]);
    for (int i=1; i<=N; i++) U[L[i]+1]++, U[O[i]]--, U[O[i]+1]++, U[R[i]]--;
    for (int i=1; i<=N; i++) U[i]+=U[i-1];

    int C=0;
    for (int i=1; i<=N; i++) C+=!U[i];
    cout << C << "\n";
    for (int i=1; i<=N; i++) if (!U[O[i]]) cout << i << " ";

    return 0;
}
