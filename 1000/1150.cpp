#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, k, ans;
int v[101010];

set<array<int, 3>> st, pq;

void Erase(set<array<int, 3>>& S, array<int, 3> A) {S.erase(S.find(A));}

signed main() {
    fastio;

    cin >> n >> k; n--;
    for (int i=0; i<=n; i++) cin >> v[i];
    for (int i=n; i>=1; i--) v[i]-=v[i-1];

    v[0]=inf;
    v[n+1]=inf;
    for (int i=0; i<=n+1; i++) {
        st.insert({i, i, v[i]});
        pq.insert({v[i], i, i});
    }

    while (k--) {
        array<int, 3> p=*pq.begin();
        ans+=p[0];
        array<int, 3> pp={p[1], p[2], p[0]};
        array<int, 3> prv=*prev(st.find(pp)), nxt=*next(st.find(pp));
        Erase(st, prv); Erase(st, pp); Erase(st, nxt);
        Erase(pq, {prv[2], prv[0], prv[1]}); Erase(pq, {pp[2], pp[0], pp[1]}); Erase(pq, {nxt[2], nxt[0], nxt[1]});
        st.insert({prv[0], nxt[1], prv[2]-pp[2]+nxt[2]});
        pq.insert({prv[2]-pp[2]+nxt[2], prv[0], nxt[1]});
    }
    cout << ans;

    return 0;
}
