#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M=100001, X=60;
vector<int> P[101010];
bool is[101010];
unordered_map<int, int> mp;
int ans;

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        int a, b; cin >> a >> b;
        P[a].push_back(b);
    }

    for (int i=0; i<=M; i++) sort(P[i].begin(), P[i].end());

    for (int i=0; i<=M; i++) {
        if (P[i].size()<X) {
            for (int j=0; j<P[i].size(); j++) for (int k=j+1; k<P[i].size(); k++)
                ans+=mp[P[i][j]*M+P[i][k]]++;
        }
        else {
            for (int j : P[i]) is[j]=1;
            for (int j=0; j<=M; j++) if (j<i || P[j].size()<X) {
                int c=0; for (int k : P[j]) c+=is[k];
                ans+=c*(c-1)/2;
            }
            for (int j : P[i]) is[j]=0;
        }
    }
    cout << ans;

    return 0;
}
