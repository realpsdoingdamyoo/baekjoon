#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, x, c, L=15;

signed main(){
    fastio;

    cin >> N;
    for (int i=0; i<L; i++) {
        cout << "? ";
        for (int j=0; j<N; j++) cout << !!(j&(1<<i));
        cout << endl;

        int a; cin >> a;
        if (a&1) c=i, x|=1<<i;
    }

    int p=0;
    for (int i=L-1; i>=0; i--) {
        if (i==c) {p|=1<<c; continue;}
        cout << "? ";
        for (int j=0; j<N; j++) cout << (p<=j && j<p+(1<<i) && (j&(1<<c)));
        cout << endl;

        int a; cin >> a;
        if (~a&1) p+=1<<i;
    }

    cout << "! " << p << " " << (p^x) << "\n";

    return 0;
}
