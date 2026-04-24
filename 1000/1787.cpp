#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n; string s;
int pi[1010101];
ll dp[1010101];

ll f(int x){
    if(x < 0) return 1LL<<60;
    ll &res = dp[x];
    if(res != -1) return res;
    if(!pi[x]) return res = 1LL<<60;
    return res = min<ll>(pi[x], f(pi[x]-1));
}

int main(){
    fastio;
    cin >> n >> s;
    for(int i=1,j=0; i<n; i++){
        while(j && s[i] ^ s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    ll sum = 0;
    memset(dp, -1, sizeof dp);

    for(int i=0; i<n; i++){
        ll t = f(i);
        //cout << i << " : " << t << "\n";
        if(t < 1e18) sum += i-t+1;
    }
    cout << sum;
}
