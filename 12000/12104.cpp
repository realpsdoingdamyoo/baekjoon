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

vi kmp(string s, string p){
    int n=s.length(), m=p.length(), j=0;
    vi pi=getpi(p);
    vi ans;
    for(int i=0; i<n; i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1) {ans.push_back(i-j); j=pi[j];}
            else j++;
        }
    }
    return ans;
}

int main() {
    fastio;
    string s, p;
    getline(cin, s); getline(cin, p);
    string pp=p+p;
    pp=pp.substr(0, pp.length()-1);
    vi ans=kmp(pp, s);
    cout << ans.size() << endl;
    return 0;
}
