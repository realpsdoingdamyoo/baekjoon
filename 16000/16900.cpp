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
    string p; cin >> p;
    int n; cin >> n;
    vi ans=getpi(p);
    cout << ans[p.length()-1]+(p.length()-ans[p.length()-1])*n;
    return 0;
}
