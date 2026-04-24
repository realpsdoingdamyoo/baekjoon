#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, A[505050], P[505050], ans=inf;
multiset<int> st;

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    for (int i=1; i<=N/2; i++) {
        P[i]=N-i; P[N-i]=i;
        st.insert(A[i]+A[N-i]);
    }
    ans=*prev(st.end())-*st.begin();

    for (int i=N; i>=2; i--) {
        int x=P[i-1], y=i-1;
        st.erase(st.find(A[x]+A[y]));
        st.insert(A[x]+A[i]);
        ans=min(ans, *prev(st.end())-*st.begin());
        P[i]=x; P[x]=i;
    }
    cout << ans;

    return 0;
}
