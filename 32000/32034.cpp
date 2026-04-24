#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        ll n, c=0; cin >> n;
        string s; cin >> s;
        ll df[2]={};
        for(int i=0; i<n; i++){
            if(s[i]=='T') df[i%2]++;
            c+=abs(df[0]-df[1]);
        }
        cout << (df[0]==df[1]?c:-1) << "\n";
    }
    return 0;
}
