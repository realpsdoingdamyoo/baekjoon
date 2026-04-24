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


int main(){
    int n; cin >> n;
    vi v(n);
    for(int i=0; i<n; i++) cin >> v[n-i-1];
    vi pi=getpi(v);
    //cout << pi.size() << endl;
    int mpl=n+1; array<int, 2> a;
    for(int i=0; i<pi.size(); i++){
        //cout << pi[i] << " ";
        if(mpl>(i-pi[i]+1)+(n-i-1)){
            a={(i-pi[i]+1), (n-i-1)};
            mpl=(i-pi[i]+1)+(n-i-1);
        }
        //cout << (i-pi[i]+1) << " " << n-i-1 << endl;
    }
    cout << a[1] << " " << a[0] << endl;
    return 0;
}
