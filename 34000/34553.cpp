#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

string s;
char p=200;
int R, X=0;

signed main(){
    fastio;

    cin >> s;
    for (char i : s) {
        if (i>p) R+=++X;
        else R+=X=1;
        p=i;
    }
    cout << R;

    return 0;
}
