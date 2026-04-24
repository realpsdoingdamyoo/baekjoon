#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    cout << "128\n";
    for(int i=0; i<5; i++) for(int j=0; j<5; j++){
        cout << "min(" << i*2+1 << "," << j*2+1 << ")\n";
        cout << "minus(" << i*2+1 << "," << j*2+1 << "," << i*5+j+1 << ")\n";
        cout << "minus(" << i*2+1 << "," << j*2+2 << "," << i*5+j+1 << ")\n";
        cout << "minus(" << i*2+2 << "," << j*2+1 << "," << i*5+j+1 << ")\n";
        cout << "minus(" << i*2+2 << "," << j*2+2 << "," << i*5+j+1 << ")\n";
    }

    cout << "max(1,1)\n";
    cout << "minus(1,1,26)\n";
    cout << "submit(1,1)\n";


    return 0;
}
