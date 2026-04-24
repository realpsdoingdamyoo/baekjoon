#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main() {
    int t; cin >> t;
    while(t--){
        string s[10003];
        int n, c=0;
        cin >> n;
        for(int i=0; i<n; i++) cin >> s[i];
        sort(s, s+n);
        for(int i=1; i<n; i++){
            if(s[i-1].substr(0, min(s[i-1].length(), s[i].length())) == s[i].substr(0, min(s[i-1].length(), s[i].length()))) c++;
        }
        if(!c) cout << "YES\n";
        else cout <<"NO\n";
    }
}
