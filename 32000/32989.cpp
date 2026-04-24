#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n;
vector<int> p[505];
vector<array<int, 2>> lnk;

signed main(){
    fastio;

    cin >> n;
    for(int i=2; i<=n; i++){
        cout << "? 1 " << i << "\n";
        cout.flush();

        int a; cin >> a;
        p[a].push_back(i);
        if(a==1) lnk.push_back({1, i});
    }

    for(int i=1; i<=n; i++){
        for(int x : p[i]) for(int y : p[i+1]){
            cout << "? " << x << " " << y << "\n";
            cout.flush();

            int a; cin >> a;
            if(a==1) lnk.push_back({x, y});
        }
        for(int x : p[i]) for(int y : p[i]) if(x<y){
            cout << "? " << x << " " << y << "\n";
            cout.flush();

            int a; cin >> a;
            if(a==1) lnk.push_back({x, y});
        }
    }

    cout << "! " << lnk.size() << "\n";
    for(array<int, 2> i : lnk) cout << i[0] << " " << i[1] << "\n";

	return 0;
}
