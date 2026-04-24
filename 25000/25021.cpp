#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;
const int MX=705;

int N, NX[MX][MX*2];
int S[MX][MX], T[MX][MX], A[MX][MX], se[MX];

int rev(int p){return p<MX?p+MX:p-MX;}
void add(int& x, int y){x=(x+y)%mod;}

signed count(vector<signed> P) {
    N=P.size();
    vector<int> V;
    for (int i=0; i<N; i++) V.push_back(P[i]<0?-P[i]:P[i]+MX);
    fill(NX[N-1], NX[N-1]+MX*2, N);

    for (int i=N-2; i>=0; i--) {
        for (int j=0; j<MX*2; j++) NX[i][j]=NX[i+1][j];
        NX[i][V[i+1]]=i+1;
    }
    for (int i=0; i<N; i++) if (V[i]<MX)
        for (int j=0; j<MX; j++) if (V[i]!=j) S[i][NX[i][rev(j)]]++;

    for (int l=1; l<N; l++) {
        for (int i=0, j=l; j<N; i++, j++) if (V[j]>MX) {
            if (V[i]<MX) {
                add(A[i][j], S[i][j]);

                int in=0;
                for (int p=0; p<MX; p++) if (V[i]!=p && NX[i][p]<j) add(in, A[NX[i][p]][j]);
                for (int p=0; p<MX; p++) if (V[i]!=p && V[j]!=rev(p)) add(S[i][NX[j][rev(p)]], in);
                for (int p=i+1; p<j; p++) if (V[p]>MX) add(A[i][j], A[i][p]*T[p][j]);
            }
            else {
                for (int p=0; p<MX; p++) if (V[i]!=rev(p) && NX[i][p]<j) add(T[i][j], S[NX[i][p]][j]);
            }
        }
    }

    int ans=0;
    for (int i=0; i<N; i++) if (V[i]<MX && !se[V[i]]) {
        se[V[i]]=1;
        for (int j=i+1; j<N; j++) ans+=A[i][j];
    }

    return ans%mod;
}
