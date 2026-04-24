#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int mod=10007;

string str;
int dp[1001][1001];
int slv(int s, int e) {
    if (s>e) return 0;
    if (s==e) return 1;
    int& ret=dp[s][e];
    if (ret!=-1) return ret;
    ret=(slv(s, e-1)+slv(s+1, e))%mod;
    ret-=slv(s+1, e-1);
    if (ret<0) ret+=mod;
    if (str[s]==str[e]) ret=(ret+slv(s+1, e-1)+1)%mod;
    return ret % mod;
}

int main() {
    for(int i=0; i<1001; i++) for(int j=0; j<1001; j++) dp[i][j]=-1;
    cin >> str; cout << slv(0, str.length()-1) % mod;
    return 0;
}
