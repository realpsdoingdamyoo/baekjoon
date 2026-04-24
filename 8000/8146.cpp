#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int P[101010];
vector<int> ans;

signed main() {
    fastio;

    int N; cin >> N;
    vector<int> V(N*2), U;
    for (int& i : V) cin >> i;

    for (int i=1; i<=N; i++) P[i]=-1;

    for (int i=0; i<V.size(); i++) {
        int sz=U.size();
        if (~P[V[i]]) {
            for (int j=P[V[i]]+1; j<sz; j++) ans.push_back(j);
            U.erase(U.begin()+P[V[i]]);
            for (int j=P[V[i]]; j<U.size(); j++) P[U[j]]=j;
        }
        else P[V[i]]=U.size(), U.push_back(V[i]);
    }
    swap(V, U); U.clear();

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << "\n";

    return 0;
}
