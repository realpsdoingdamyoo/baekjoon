#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

void solve(){
    string a, b; cin >> a >> b;
    string s; cin >> s;

    int n=a.size(), m=b.size(), p=s.size();

    vector<array<int, 2>> A(p, {0, 0}), B(p, {0, 0});
    vector<array<int, 26>> as(n), bs(m);
    for(array<int, 26>& i : as) for(int& j : i) j=0;
    for(array<int, 26>& i : bs) for(int& j : i) j=0;

    for(int i=0, j=0; i<p; i++, j++){
        while(a[j]!=s[i]) j++;
        A[i][0]=j;
    }

    for(int i=0, j=0; i<p; i++, j++){
        while(b[j]!=s[i]) j++;
        B[i][0]=j;
    }

    for(int i=p-1, j=n-1; i>=0; i--, j--){
        while(a[j]!=s[i]) j--;
        A[i][1]=j;
    }

    for(int i=p-1, j=m-1; i>=0; i--, j--){
        while(b[j]!=s[i]) j--;
        B[i][1]=j;
    }

    for(int i=0; i<n; i++){
        if(i) as[i]=as[i-1];
        as[i][a[i]-'a']++;
    }

    for(int i=0; i<m; i++){
        if(i) bs[i]=bs[i-1];
        bs[i][b[i]-'a']++;
    }

    int ret=0;
    for(int i=0; i<p-1; i++){
        int As=A[i][0]+1, Ae=A[i+1][1]-1;
        int Bs=B[i][0]+1, Be=B[i+1][1]-1;
        for(int j=0; j<26; j++) if(as[Ae][j]-as[As-1][j] && bs[Be][j]-bs[Bs-1][j]) ret=1;
    }

    if(A[0][1] && B[0][1]) for(int j=0; j<26; j++) if(as[A[0][1]-1][j] && bs[B[0][1]-1][j]) ret=1;
    for(int j=0; j<26; j++) if(as[n-1][j]-as[A[p-1][0]][j] && bs[m-1][j]-bs[B[p-1][0]][j]) ret=1;

    cout << ret << "\n";
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
