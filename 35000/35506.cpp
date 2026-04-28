#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

void print(int x) {
    while (x--) cout << " ";
}

signed main() {
    fastio;

    int N; cin >> N;

    for (int i=1; i<=N; i++) {
        print(N*2-i);
        cout << "*";
        print(N);
        cout << "*";
        print(i*2-1);
        cout << "*";
        print(N-i);
        cout << "\n";
    }
    for (int i=1; i<=N; i++) {
        print(N-i);
        cout << "*";
        print(i*2+N-1);
        cout << "*";
        print(N*2-i*2+1);
        cout << "*";
        print(i-1);
        cout << "\n";
    }


    return 0;
}
