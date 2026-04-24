#include <bits/stdc++.h>    
using namespace std;    
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int T,m;
string a,b;
vector<int> sol2(string s){
    vector<int> ret(m+1);
    int cur=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') cur++;
        else {
            cur--;
            if(s[i-1]=='('){
                ret[cur]++;
            }
        }
    }
    for(int i=0;i<ret.size()-1;i++){
        ret[i+1]+=ret[i]/2;
        ret[i]%=2;
    }
    return ret;
}
string sol(){
    vector<int> pa = sol2(a);
    vector<int> pb = sol2(b);
    for(int i=pa.size()-1;i>=0;i--){
        if(pa[i] < pb[i]) return "<";
        if(pa[i] > pb[i]) return ">"; 
    }
    return "=";
}
int main(){
    fastio;
    cin >> T;
    while(T--){
        cin >> a >> b;
        m=max(a.size(),b.size());
        m/=2;
        cout << sol() << '\n';
    }
}
