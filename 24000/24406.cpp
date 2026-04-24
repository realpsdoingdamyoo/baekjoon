#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int C[200], V[200];
int L[101010][10][43], LV[101010][10], LC[101010][43], LS[101010];
int R[101010][10][43], RV[101010][10], RC[101010][43], RS[101010];

signed main(){
    fastio;

    for (int i=0; i<10; i++) C["AEIOUaeiou"[i]]=i, V["AEIOUaeiou"[i]]=1;
    for (int i='A', j=0; i<='z'; i++) if (!V[i] && (i<='Z' || 'a'<=i)) C[i]=++j;

    string S; cin >> S;
    int N=S.length(); S=" "+S;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<10; j++) for (int k=0; k<=42; k++) L[i][j][k]=L[i-1][j][k];
        int c=C[S[i]];
        if (V[S[i]]) L[i][c][0]++;
        else for (int j=0; j<10; j++) L[i][j][c]+=L[i-1][j][0];
        for (int j=0; j<10; j++) for (int k=1; k<=42; k++)
            LV[i][j]=(LV[i][j]+L[i][j][k])%mod, LC[i][k]=(LC[i][k]+L[i][j][k])%mod, LS[i]=(LS[i]+L[i][j][k])%mod, L[i][j][k]%=mod;
    }
    for (int i=N; i>=1; i--) {
        for (int j=0; j<10; j++) for (int k=0; k<=42; k++) R[i][j][k]=R[i+1][j][k];
        int c=C[S[i]];
        if (V[S[i]]) R[i][c][0]++;
        else for (int j=0; j<10; j++) R[i][j][c]+=R[i+1][j][0];
        for (int j=0; j<10; j++) for (int k=1; k<=42; k++)
            RV[i][j]=(RV[i][j]+R[i][j][k])%mod, RC[i][k]=(RC[i][k]+R[i][j][k])%mod, RS[i]=(RS[i]+R[i][j][k])%mod, R[i][j][k]%=mod;
    }

    int ans=0;
    for (int i=1; i<=N; i++) if (V[S[i]]) {
        int c=C[S[i]];
        ans+=(LS[i]-LV[i][c])*(RS[i]-RV[i][c])%mod;
        for (int j=0; j<10; j++) if (j!=c) ans-=LV[i][j]*RV[i][j]%mod;
        for (int j=1; j<=42; j++) ans-=(LC[i][j]-L[i][c][j])*(RC[i][j]-R[i][c][j])%mod;
        for (int j=0; j<10; j++) if (j!=c) for (int k=1; k<=42; k++)
            ans+=L[i][j][k]*R[i][j][k]%mod;
    }
    cout << (ans%mod+mod)%mod;

    return 0;
}
