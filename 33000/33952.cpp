#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

signed main(){
    fastio;

    int n; cin >> n;
    string s; cin >> s;
    int c=0, p=0;
    for(char i : s) if(i=='C') c++; else p++;
    if(c*2!=p){cout << "NO"; return 0;}

    if(s.front()=='C' || s.back()=='C'){
        cout << "YES"; return 0;
    }

    c=0, p=0;
    for(int i=0; i<n-1; i++){
        if(s[i]=='C') c++; else p++;
        if(s[i]=='C' && s[i+1]=='C' && c*2==p){
            cout << "YES"; return 0;
        }
    }

    cout << "NO";
    return 0;
}
