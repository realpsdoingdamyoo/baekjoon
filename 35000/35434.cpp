#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, K, A[1010101], ans;
int C, U[1010101];
int sp[1010101][20];
 
signed main() {
    fastio;
 
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> A[i];
 
    int j=0;
    while (j<N && C<K) j++, C+=!U[A[j]], U[A[j]]++;
 
    if (C<K) {cout << "0"; return 0;}
 
    for (int i=1; i<=N; i++) {
        while (C<K) j=j%N+1, C+=!U[A[j]], U[A[j]]++;
        sp[i][0]=(j-i+N)%N+1;
        U[A[i]]--; C-=!U[A[i]];
    }
 
    for (j=1; j<20; j++) for (int i=1; i<=N; i++)
        sp[i][j]=sp[i][j-1]+sp[(i+sp[i][j-1]-1)%N+1][j-1];
 
    for (int i=1; i<=N; i++) {
        int g=0, c=0, p=i;
        for (j=19; j>=0; j--) if (g+sp[p][j]<=N)
            g+=sp[p][j], p=(p+sp[p][j]-1)%N+1, c+=1<<j;
        ans=max(ans, c);
    }
    cout << ans;
 
    return 0;
}
