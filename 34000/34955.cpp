#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, M, B[101010], F[101010], C[101010], D, R, P;
multiset<int> st;
vector<array<int, 2>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> B[i];
    for (int i=1; i<=M; i++) cin >> F[i], st.insert(F[i]);
    sort(F+1, F+M+1);

    for (int i=1; i<=N; i++) C[upper_bound(F+1, F+M+1, B[i])-F]++;
    for (int i=1; i<=M; i++) C[i+1]+=C[i]-!!C[i], D+=C[i]=!!C[i];
    for (int i=M-D+1; i<=M; i++) R+=F[i];

    for (int i=1, x; i<=N; i++) if (st.size() && B[i]<*prev(st.end())) {
        vec.push_back({0, B[i]}); x=*st.upper_bound(B[i]);
        st.erase(st.find(x)); P+=x; pq.push(x);
    }

    while (P<R) {
        int x=pq.top(); pq.pop(); P-=x; vec.push_back({1, x}); vec.push_back({0, x});
        x=*st.upper_bound(x); st.erase(st.find(x)); P+=x; pq.push(x);
    }

    cout << vec.size() << "\n";
    for (array<int, 2> i : vec) cout << (i[0]?"bait ":"fish ") << i[1] << "\n";
    cout << R;


    return 0;
}
