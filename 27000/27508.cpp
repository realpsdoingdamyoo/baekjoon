#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int max_item_sum(vector<vector<int>> V) {
    int N=V.size(), ans=-inf;
    vector<vector<int>> UL(N, vector<int>(N, -inf));
    vector<vector<int>> DL(N, vector<int>(N, -inf));
    vector<vector<int>> UR(N, vector<int>(N, -inf));
    vector<vector<int>> DR(N, vector<int>(N, -inf));
    UL[0][0]=DL[N-1][0]=UR[0][N-1]=DR[N-1][N-1]=0;

    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        if (i) UL[i][j]=max(UL[i][j], UL[i-1][j]);
        if (j) UL[i][j]=max(UL[i][j], UL[i][j-1]);
        UL[i][j]+=V[i][j];
    }
    for (int i=0; i<N; i++) for (int j=N-1; j>=0; j--) {
        if (i) UR[i][j]=max(UR[i][j], UR[i-1][j]);
        if (j<N-1) UR[i][j]=max(UR[i][j], UR[i][j+1]);
        UR[i][j]+=V[i][j];
    }
    for (int i=N-1; i>=0; i--) for (int j=0; j<N; j++) {
        if (i<N-1) DL[i][j]=max(DL[i][j], DL[i+1][j]);
        if (j) DL[i][j]=max(DL[i][j], DL[i][j-1]);
        DL[i][j]+=V[i][j];
    }
    for (int i=N-1; i>=0; i--) for (int j=N-1; j>=0; j--) {
        if (i<N-1) DR[i][j]=max(DR[i][j], DR[i+1][j]);
        if (j<N-1) DR[i][j]=max(DR[i][j], DR[i][j+1]);
        DR[i][j]+=V[i][j];
    }

    vector<vector<int>> U(N, vector<int>(N, -inf));
    vector<vector<int>> D(N, vector<int>(N, -inf));
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        if (j) U[i][j]=max(U[i][j], UL[i][j-1]+UR[i][j]);
        if (j<N-1) U[i][j]=max(U[i][j], UL[i][j]+UR[i][j+1]);
        if (i) U[i][j]=max(U[i][j], U[i-1][j]+V[i][j]);
    }
    for (int i=N-1; i>=0; i--) for (int j=0; j<N; j++) {
        if (j) D[i][j]=max(D[i][j], DL[i][j-1]+DR[i][j]);
        if (j<N-1) D[i][j]=max(D[i][j], DL[i][j]+DR[i][j+1]);
        if (i<N-1) D[i][j]=max(D[i][j], D[i+1][j]+V[i][j]);
    }
    for (int i=1; i<N; i++) for (int j=0; j<N; j++) {
        ans=max(ans, U[i-1][j]+D[i][j]);
    }

    vector<vector<int>> L(N, vector<int>(N, -inf));
    vector<vector<int>> R(N, vector<int>(N, -inf));
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        if (i) L[i][j]=max(L[i][j], UL[i-1][j]+DL[i][j]);
        if (i<N-1) L[i][j]=max(L[i][j], UL[i][j]+DL[i+1][j]);
        if (j) L[i][j]=max(L[i][j], L[i][j-1]+V[i][j]);
    }
    for (int i=0; i<N; i++) for (int j=N-1; j>=0; j--) {
        if (i) R[i][j]=max(R[i][j], UR[i-1][j]+DR[i][j]);
        if (i<N-1) R[i][j]=max(R[i][j], UR[i][j]+DR[i+1][j]);
        if (j<N-1) R[i][j]=max(R[i][j], R[i][j+1]+V[i][j]);
    }
    for (int i=0; i<N; i++) for (int j=1; j<N; j++) {
        ans=max(ans, L[i][j-1]+R[i][j]);
    }

    for (int i=1; i<N-1; i++) for (int j=1; j<N-1; j++) {
        ans=max(ans, UL[i-1][j]+UR[i][j+1]+DR[i+1][j]+DL[i][j-1]+V[i][j]);
        ans=max(ans, UL[i][j-1]+UR[i-1][j]+DR[i][j+1]+DL[i+1][j]+V[i][j]);
    }

    return ans;
}
