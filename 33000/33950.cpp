#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main(){
    fastio;

    int t; cin >>t;
    while(t--){
        string s; cin >> s;
        for(int i=0; i<s.length(); i++){
            cout << s[i];
            if(i!=s.length()-1 && s[i]=='P' && s[i+1]=='O') cout << 'H';
        }
        cout << "\n";
    }

    return 0;
}
