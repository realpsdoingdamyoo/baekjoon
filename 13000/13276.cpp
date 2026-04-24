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
    string s, p1, p2;
    cin >> s >> p1 >> p2;
    vi p1kmp=kmp(s, p1);
    vi p2kmp=kmp(s, p2);
    unordered_set<string> us;
    for(int st : p1kmp) for(int en : p2kmp){
        if(st+p1.length()>en+p2.length() || st>en) continue;
        //cout << "(" << st << " " << en << " " << s.substr(st, en-st+p2.length()) << ")" << endl;
        us.emplace(s.substr(st, en-st+p2.length()));
    }
    cout << us.size();

    //for(string p : us) cout << p << endl;

    return 0;
}
