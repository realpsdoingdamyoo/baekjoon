#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

signed main() {
    fastio;

    vector<int> pr={29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
    vector<map<int, int>> F;

    for (int p : pr) {
        map<int, int> mp, ret;
        int pv=1;
        for (int i=1; i<40000; i++) {
            pv=pv*p%mod;
            if (mp.find(mod-pv-1)!=mp.end()) {
                ret[0]=1; ret[mp[mod-pv-1]]=1; ret[i]=1;
                break;
            }
            if (mp.find(mod-pv+1)!=mp.end()) {
                ret[0]=1; ret[mp[mod-pv+1]]=-1; ret[i]=-1;
                break;
            }
            if (mp.find(pv+1)!=mp.end()) {
                ret[0]=1; ret[mp[pv+1]]=-1; ret[i]=1;
                break;
            }
            if (mp.find(pv-1)!=mp.end()) {
                ret[0]=1; ret[mp[pv-1]]=1; ret[i]=-1;
                break;
            }
            mp[pv]=i;
        }
        F.push_back(ret);
    }

    for (int i=0; i+1<F.size(); i+=2) {
        F.emplace_back();
        for (pair<int, int> j : F[i]) for (pair<int, int> k : F[i+1])
            F.back()[j.first+k.first]+=j.second*k.second;
    }

    string A(300000, 'a'), B(300000, 'a');
    for (pair<int, int> i : F.back()) {
        if (i.second<0) A[i.first]-=i.second;
        else B[i.first]+=i.second;
    }
    cout << A << "\n" << B;

    return 0;
}
