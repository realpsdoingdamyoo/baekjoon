#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

string rvs(string s){
    string t;
    for(int i=0; i<s.length(); i++) t+=s[s.length()-1-i];
    return t;
}

int main() {
    string a, b;
    cin >> a >> b;
    while(a.length()<b.length()){
        if(b[b.length()-1]=='A') b=b.substr(0, b.length()-1);
        else b=rvs(b.substr(0, b.length()-1));
    }
    cout << (a==b);
}
