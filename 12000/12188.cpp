#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

char A[10][10];

void solve(int t) {
    int N, ans=0; cin >> N;
    for (int i=0; i<=9; i++) for (int j=0; j<=9; j++) A[i][j]=' ';
    for (int i=1; i<=N; i++) {
        char a, b, c, d; cin >> a >> b >> c >> d;
        A[a-'A'+1][b-'0']=d;
    }
    for (int i=1; i<=8; i++) for (int j=1; j<=8; j++) {
        if (A[i][j]=='K') {
            for (int x=i-1; x<=i+1; x++) for (int y=j-1; y<=j+1; y++) if (x!=i || y!=j)
                if (A[x][y]!=' ') ans++;
        }
        if (A[i][j]=='R' || A[i][j]=='Q') {
            for (int x=i-1, y=j; x>=1; x--) if (A[x][y]!=' ') {ans++; break;}
            for (int x=i+1, y=j; x<=8; x++) if (A[x][y]!=' ') {ans++; break;}
            for (int x=i, y=j-1; y>=1; y--) if (A[x][y]!=' ') {ans++; break;}
            for (int x=i, y=j+1; y<=8; y++) if (A[x][y]!=' ') {ans++; break;}
        }
        if (A[i][j]=='B' || A[i][j]=='Q') {
            for (int x=i-1, y=j-1; x>=1 && y>=1; x--, y--) if (A[x][y]!=' ') {ans++; break;}
            for (int x=i-1, y=j+1; x>=1 && y<=8; x--, y++) if (A[x][y]!=' ') {ans++; break;}
            for (int x=i+1, y=j-1; x<=8 && y>=1; x++, y--) if (A[x][y]!=' ') {ans++; break;}
            for (int x=i+1, y=j+1; x<=8 && y<=8; x++, y++) if (A[x][y]!=' ') {ans++; break;}
        }
        if (A[i][j]=='N') {
            for (int x : {-2, -1, 1, 2}) for (int y : {-2, -1, 1, 2}) if (x*x!=y*y)
                if (1<=min(i+x, j+y) && max(i+x, j+y)<=8 && A[i+x][j+y]!=' ') ans++;
        }
        if (A[i][j]=='P') {
            if (A[i+1][j-1]!=' ') ans++;
            if (A[i+1][j+1]!=' ') ans++;
        }
    }
    cout << "Case #" << t << ": " << ans << "\n";
}

signed main(){
    fastio;

    int T; cin >> T;
    for (int i=1; i<=T; i++) solve(i);

    return 0;
}
