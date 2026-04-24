#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

vector<array<int, 2>> p;
int ans[2020][2020];

signed main(){
    fastio;

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        p.push_back({a, i});
    }

    while(p.size()){
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        for(int i=1; i<=p[0][0]; i++){
            if(i>=p.size() || p[i][0]==0){
                cout << "-1";
                return 0;
            }
            ans[p[0][1]][p[i][1]]=ans[p[i][1]][p[0][1]]=1;
            p[i][0]--;
        }
        p.erase(p.begin());
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
