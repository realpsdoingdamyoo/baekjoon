#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

map<int, array<int, 2>> mp;

signed main(){
    fastio;

    int N; cin >> N;
    for (int i=2; i*i<=N; i++) {
        int S=1+i+i*i, x=i*i*i;
        for (int j=3; S<=N; j++) {
            mp[S]={i, j}; S+=x; x*=i;
        }
    }

    for (int i=1; i*i<=N; i++) if (N%i==0) {
        if (mp.find(N/i)!=mp.end()) {
            int p=i;
            cout << mp[N/i][1] << "\n";
            for (int j=0; j<mp[N/i][1]; j++) {
                cout << p << " ";
                p*=mp[N/i][0];
            }
            return 0;
        }
        if (mp.find(i)!=mp.end()) {
            int p=N/i;
            cout << mp[i][1] << "\n";
            for (int j=0; j<mp[i][1]; j++) {
                cout << p << " ";
                p*=mp[i][0];
            }
            return 0;
        }
    }
    cout << "-1";

    return 0;
}
