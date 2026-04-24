#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
string s;
vector<int> ans;
int u[100];

bool bck(int p) {
    if (p==s.length()) return true;
    if (p+2<=s.length()) {
        int x=(s[p]-'0')*10+(s[p+1]-'0');
        if (!u[x] && x && x<=N) {
            u[x]=1; ans.push_back(x);
            if (bck(p+2)) return true;
            u[x]=0; ans.pop_back();
        }
    }
    int x=(s[p]-'0');
    if (!u[x] && x && x<=N) {
        u[x]=1; ans.push_back(x);
        if (bck(p+1)) return true;
        u[x]=0; ans.pop_back();
    }
    return false;
}

signed main(){
    fastio;

    cin >> s;
    while (K+(N>=9)+1<=s.length()) K+=(N>=9)+1, N++;
    bck(0);

    for (int i : ans) cout << i << " ";

    return 0;
}
