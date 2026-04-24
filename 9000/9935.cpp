#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main() {
    string s, t;
    cin >> s >> t;
    vector<char> v;
    for(int i=0; i<s.length(); i++){
        int c=1;
        v.push_back(s[i]);
        if(v.size()>=t.length()){
            for(int j=0; j<t.length(); j++) if(v[v.size()-1-j]!=t[t.length()-1-j]) c=0;
            if(c){
                for(int j=0; j<t.length(); j++) v.pop_back();
            }
        }
    }
    int c=1;
    if(v.size()>=t.length()){
        for(int j=0; j<t.length(); j++) if(v[v.size()-1-j]!=t[t.length()-1-j]) c=0;
        if(c){
            for(int j=0; j<t.length(); j++) v.pop_back();
        }
    }
    if(v.size()==0) cout << "FRULA";
    else for(int j=0; j<v.size(); j++) cout << v[j]; cout << endl;
}
