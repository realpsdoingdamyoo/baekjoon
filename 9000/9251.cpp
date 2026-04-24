#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int lcs[1001][1001];

int main() {
    string a, b;
    cin >> a >> b;
    int n=a.length(), m=b.length();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i*j==0) lcs[i][j]=0;
            else{
                lcs[i][j]=max(lcs[i][j-1], lcs[i-1][j]);
                lcs[i][j]=max(lcs[i][j], (a[i-1]==b[j-1])+lcs[i-1][j-1]);
            }
        }
    }
    cout << lcs[n][m];
}
