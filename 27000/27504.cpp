#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vi getpi(vi p){
    int m=p.size(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vi kmp(vi s, vi p){
    int n=s.size(), m=p.size(), j=0;
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
    int n, sz, c=0; cin >> n;
    vector<vi> v(n);
    for(int i=0; i<n; i++){
        cin >> sz; v[i].resize(sz);
        for(int j=0; j<sz; j++) cin >> v[i][j];
        for(int j=0; j<sz-1; j++) v[i][j]-=v[i][j+1];
        v[i].pop_back();
    }
    cin >> sz;
    vi p(sz);
    for(int j=0; j<sz; j++) cin >> p[j];
    for(int j=0; j<sz-1; j++) p[j]-=p[j+1];
    p.pop_back();
    for(int i=0; i<n; i++){
        vi kp=kmp(v[i], p);
        if(kp.size()) cout << i+1+0*c++ << "\n";
    }
    if(!c) cout << "-1\n";
    return 0;
}
