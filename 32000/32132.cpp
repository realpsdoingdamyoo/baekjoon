#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n; cin >> n;
    string s, p; cin >> s;
    for(int i=0; i<n; i++){
        if(p.size()<2 || (p.substr(p.size()-2, 2)!="PS" || (s[i]>'5' || s[i]<'4'))){
            p+=s[i];
        }
    }
    cout << p;
    return 0;
}
