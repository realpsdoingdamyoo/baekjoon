#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, B=350;
vector<int> V[50505];
map<array<int, 2>, int> mp;

signed main(){
    fastio;

    cin >> N;
    for (int T=1; T<=N; T++) {
        int K; cin >> K; V[T].resize(K);
        for (int& i : V[T]) cin >> i;
    }

    for (int T=1; T<=N; T++) {
        if (V[T].size()>=B) {
            unordered_set<int> st;
            for (int i : V[T]) st.insert(i);
            for (int i=1; i<=N; i++) if (i!=T) {
                int p=-1;
                for (int j : V[i]) if (st.find(j)!=st.end()) {
                    if (p==-1) p=j;
                    else {cout << p << " " << j << " " << i << " " << T; return 0;}
                }
            }
        }
        else {
            for (int i : V[T]) for (int j : V[T]) if (i<j) {
                if (mp.find({i, j})!=mp.end()) {
                    cout << i << " " << j << " " << mp[{i, j}] << " " << T;
                    return 0;
                }
                mp[{i, j}]=T;
            }
        }
    }
    cout << "impossible";

    return 0;
}
