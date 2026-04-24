#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, Q;
string s;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

signed main() {
    fastio;

    cin >> N >> Q; cin >> s;
    for (int i=1; i<=Q; i++) {
        int x; char y; cin >> x >> y; s[x-1]=y;

        int p=0, a=0, b=0;
        for (char c : s) {
            if (c=='L') p=(p+3)%4;
            else if (c=='R') p=(p+1)%4;
            else {
                if (p==0) a++;
                else if (p==1) b++;
                else if (p==2) a--;
                else b--;
            }
        }
        if (p!=0 || (a==0 && b==0)) cout << "0\n";
        else cout << "1\n";
    }

    return 0;
}
