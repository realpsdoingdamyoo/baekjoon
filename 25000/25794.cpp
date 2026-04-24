#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int X, Y; cin >> X >> Y; if (X<Y) swap(X, Y);
    if (X==Y) {
        cout << "7\n";
        cout << X << " " << Y << "\n";
        cout << X*2 << " " << 0 << "\n";
        cout << X*3 << " " << -Y << "\n";
        cout << X*2 << " " << -Y*2 << "\n";
        cout << X << " " << -Y*3 << "\n";
        cout << 0 << " " << -Y*2 << "\n";
        cout << X << " " << -Y << "\n";
        return 0;
    }
    if (Y==0) {
        cout << "7\n";
        cout << X << " " << 0 << "\n";
        cout << X << " " << X << "\n";
        cout << X << " " << X*2 << "\n";
        cout << 0 << " " << X*2 << "\n";
        cout << -X << " " << X*2 << "\n";
        cout << -X << " " << X << "\n";
        cout << 0 << " " << X << "\n";
        return 0;
    }

    cout << "15\n";
    cout << X << " " << -Y << "\n";
    cout << X-Y << " " << X-Y << "\n";
    cout << X*2-Y << " " << X << "\n";
    cout << X-Y << " " << X+Y << "\n";
    cout << X << " " << X*2+Y << "\n";
    cout << 0 << " " << X*2 << "\n";
    cout << -Y << " " << X*3 << "\n";
    cout << -Y*2 << " " << X*2 << "\n";
    cout << -X-Y*2 << " " << X*2+Y << "\n";
    cout << -X-Y << " " << X+Y << "\n";
    cout << -X*2-Y << " " << X << "\n";
    cout << -X-Y << " " << X-Y << "\n";
    cout << -X-Y*2 << " " << -Y << "\n";
    cout << -Y*2 << " " << 0 << "\n";
    cout << -Y << " " << X << "\n";


    return 0;
}
