#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;

signed main(){
    fastio;

    cin >> N;
    int p=(N+1)/2;
    for (int i=1; i<=N; i++) {
        cout << p << " ";
        if (i%2==1) p+=i; else p-=i;
    }


    return 0;
}
