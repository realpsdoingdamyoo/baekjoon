#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int fac[4040]={1}, ifac[4040];
int N, I[4040], DP[4040][4040], S[4040][4040], P[4040][4040];

int solve(vector<array<int, 2>> v) {
    N=v.size();

    for (int i=1; i<=N*2; i++) for (int j=1; j<=N*2; j++) DP[i][j]=0, S[i][j]=0, P[i][j]=0;
    for (array<int, 2> i : v) S[i[0]][i[1]]=1;
    for (int i=N*2; i>=1; i--) for (int j=i; j<=N*2; j++)
        S[i][j]+=S[i+1][j]+S[i][j-1]-S[i+1][j-1];
    for (array<int, 2> i : v) DP[i[0]][i[1]]=fac[N-1]*ifac[N-S[i[0]][i[1]]]%mod;
    for (int i=0; i<N; i++) I[v[i][0]]=-i-1, I[v[i][1]]=i+1;

    for (int i=N*2; i>=1; i--) for (int j=i+1; j<=N*2; j++) {
        P[i][j]=(P[i+1][j]+P[i][j-1]-P[i+1][j-1]+mod)%mod;
        int lx=v[-I[i]-1][1], rx=v[I[j]-1][0];
        if (I[i]>0 || I[j]<0 || j<lx || rx<i) continue;

        if (I[i]+I[j]==0) DP[i][j]=(DP[i][j]+P[i][j]*ifac[N-S[i][j]])%mod;
        else {
            int ls=(P[i+1][j]-P[i+1][j-1]-P[lx][j]+P[lx][j-1]+mod*2)%mod;
            int rs=(P[i][j-1]-P[i+1][j-1]-P[i][rx]+P[i+1][rx]+mod*2)%mod;
            DP[i][j]=(DP[i][j]+(ls+rs)*ifac[N-S[i][j]])%mod;
        }
        if (N-S[i][j]) P[i][j]=(P[i][j]+DP[i][j]*fac[N-S[i][j]-1])%mod;
    }
    return DP[1][N*2];
}

signed count_removals(vector<signed> S, vector<signed> E) {
    for (int i=1; i<=4000; i++) fac[i]=fac[i-1]*i%mod;
    ifac[4000]=655050076;
    for (int i=4000; i>=1; i--) ifac[i-1]=ifac[i]*i%mod;

    vector<array<int, 2>> u, v, ret; S.push_back(mod);
    for (int i=0; i<S.size(); i++) u.push_back({S[i], E[i]});
    sort(u.begin(), u.end());
    for (int i=0; i<S.size(); i++) S[i]=u[i][0], E[i]=u[i][1];
    for (int i=0; i<E.size(); i++) {
        int mx=E[i];
        while (max(mx, (int)E[i])>S[i+1])
            v.push_back({S[i], E[i]}), mx=max(mx, (int)E[i]), i++; v.push_back({S[i], E[i]});
        int x=v[0][0]-1; for (array<int, 2>& j : v) j[0]-=x, j[1]-=x;
        ret.push_back({(int)v.size(), solve(v)});
        v.clear();
    }

    int ans=1, p=0, c=0;
    sort(ret.begin(), ret.end());
    for (array<int, 2> i : ret) {
        ans=ans*i[1]%mod;
        if (i[0]==p) c++; else p=i[0], c=1;
        ans=ans*c%mod;
    }

    return ans;
}
