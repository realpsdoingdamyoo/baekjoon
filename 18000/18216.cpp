#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N;
string S[1010];
map<string, int> mp[2], vis[2];
priority_queue<pair<array<int, 2>, string>, vector<pair<array<int, 2>, string>>, greater<pair<array<int, 2>, string>>> pq;
set<string> st;

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> S[i], st.insert(S[i]);
    for (int i=1; i<=N; i++) pq.push({{-inf, 1}, S[i]}), mp[1][S[i]]=-inf;

    while (pq.size()) {
        int t=pq.top().first[1]; string s=pq.top().second; pq.pop();
        if (vis[t][s]++) continue;

        for (int i=1; i<=N; i++) if (t==0 || S[i]!=s) {
            string a=s, b=S[i];
            if (a.length()>b.length()) swap(a, b);

            if (a==b.substr(0, a.length())) {
                string p=b.substr(a.length());
                mp[0][p]=min(mp[0][p], mp[t][s]+(int)a.length());
                pq.push({{(int)(mp[t][s]+a.length()), 0}, b.substr(a.length())});
            }
        }
    }
    if (mp[0][""]==0) cout << 0;
    else cout << mp[0][""]+inf;

    return 0;
}
