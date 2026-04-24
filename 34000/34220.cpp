#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
vector<int> lnk[101010];

signed main(){
    fastio;

    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    int p=1;
    for (int i=1; i<=n; i++) if (lnk[i].size()>lnk[p].size()) p=i;

    if (lnk[p].size()>=3) {
        cout << "3\n";
        cout << lnk[p][0] << " " << lnk[p][1] << "\n";
        cout << lnk[p][1] << " " << lnk[p][2] << "\n";
        cout << lnk[p][2] << " " << lnk[p][0] << "\n";
    }
    else {
        int q;
        if (lnk[lnk[p][0]].size()==2) q=lnk[p][0]; else q=lnk[p][1];
        if (lnk[p][0]==q) swap(lnk[p][0], lnk[p][1]);
        if (lnk[q][0]==p) swap(lnk[q][0], lnk[q][1]);
        cout << "3\n";
        cout << p << " " << lnk[q][0] << "\n";
        cout << q << " " << lnk[p][0] << "\n";
        cout << lnk[p][0] << " " << lnk[q][0] << "\n";
    }


    return 0;
}
