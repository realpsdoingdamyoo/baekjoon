#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=1e9+7, inf=2e9;

int X[22], R, K;
string s;

int gcd(int a, int b){return b?gcd(b, a%b):a;}

int solve() {
    unordered_map<int, int> DP0, DP1;

    int nz=0;
    for (int i=20; i>=0; i--) {
        unordered_map<int, int> dp0, dp1;
        for (int j=0; j<=9; j++) {
            for (pair<int, int> x : DP0) {
                int k=x.first, v=x.second;
                if (j==0) k=1; else k/=gcd(k, j);
                dp0[k]+=v;
            }
        }
        for (int j=0; j<X[i]; j++) {
            for (pair<int, int> x : DP1) {
                int k=x.first, v=x.second;
                if (j==0) k=1; else k/=gcd(k, j);
                dp0[k]+=v;
            }
        }
        for (pair<int, int> x : DP1) {
            int k=x.first, v=x.second;
            if (X[i]==0) k=1; else k/=gcd(k, X[i]);
            dp1[k]+=v;
        }

        if (nz==0) {
            for (int j=1; j<=X[i]; j++) {
                int k=K;
                if (j==0) k=1; else k/=gcd(k, j);
                if (j==X[i]) dp1[k]++; else dp0[k]++;
            }
        }
        else {
            for (int j=1; j<=9; j++) {
                int k=K;
                if (j==0) k=1; else k/=gcd(k, j);
                dp0[k]++;
            }
        }

        swap(DP0, dp0); swap(DP1, dp1);
        for (pair<int, int> j : DP0) DP0[j.first]%=MOD;
        for (pair<int, int> j : DP1) DP1[j.first]%=MOD;

        nz+=X[i];
    }
    return DP0[1]+DP1[1];
}


signed main() {
    fastio;

    cin >> K;

    cin >> s;
    reverse(s.begin(), s.end());
    for (int i=0; i<s.length(); i++) X[i]=s[i]-'0';
    for (int i=0;; i++) if (X[i]) {X[i]--; break;} else X[i]=9;
    R-=solve();

    cin >> s;
    reverse(s.begin(), s.end());
    for (int i=0; i<s.length(); i++) X[i]=s[i]-'0';
    R+=solve();

    cout << (R%MOD+MOD)%MOD;

    return 0;
}
