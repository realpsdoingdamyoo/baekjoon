#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vi getpi(string p){
    int m=p.length(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

int main() {
    fastio;
    string s; cin >> s;
    vi pi=getpi(s);
    for(int i=0; i<s.length(); i++){
        if((i+1)%(i+1-pi[i])==0 && (i+1)/(i+1-pi[i])>1){
            cout << i+1 << " ";
            cout <<(i+1)/(i+1-pi[i]) << "\n";
        }
    }
    return 0;
}
