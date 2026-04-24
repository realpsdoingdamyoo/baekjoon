#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int cnt(string s) {
    int n=s.length();
    vector<array<int, 3>> dp(n+1, {0, 0, 0});
    for (int i=1; i<=n; i++) {
        dp[i]=dp[i-1];
        if (s[i-1]=='J') dp[i][0]++;
        else if (s[i-1]=='O') dp[i][1]+=dp[i][0];
        else dp[i][2]+=dp[i][1];
    }
    return dp[n][2];

}

int cnt2(string s) {
    int jc=0, ic=0, ret=0;
    for (char i : s) ic+=(i=='I');
    for (char i : s) {
        jc+=(i=='J'); ic-=(i=='I');
        ret=max(ret, ic*jc);
    }
    return ret;
}

int n;
string s;

signed main() {
    fastio;

    cin >> n >> s;
    int ans=max(cnt('J'+s), cnt(s+'I'));
    ans=max(ans, cnt(s)+cnt2(s));
    cout << ans;

    return 0;
}
