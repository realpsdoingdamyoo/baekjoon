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

int main() {
    int n; cin >> n;
    vi s(n);
    for(int i=n-1; i>=0; i--) cin >> s[i];
    vi ans=getpi(s);
    int mxi=-1, mx=-1;
    for(int i=0; i<ans.size(); i++){
        if(ans[i]>mx){mxi=1; mx=ans[i];}
        else if(ans[i]==mx) mxi++;
    }
    if(mx==0) cout << -1;
    else cout << mx << " " << mxi << endl;
    return 0;
}
