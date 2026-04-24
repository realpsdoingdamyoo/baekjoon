#include "Anna.h"
#include "Bruno.h"
#include <bits/stdc++.h>
using namespace std;
#define si signed
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

const int N=140;

si Declare(){return N;}

int DP[N+10];
pair<vector<si>, vector<si>> Anna(int A) {
    DP[0]=DP[1]=1; DP[2]=2;
    for (int i=3; i<=N; i++) DP[i]=DP[i-2]+DP[i-3]+1;

    int L=1, S=accumulate(DP, DP+N, 0LL);
    if (A>S) A-=S, L=0;

    vector<si> rS={L}, rT={L};

    int K=0;
    while (A>=DP[K]) A-=DP[K], K++;
    for (int D=K; D>=1;) {
        if (!A) {
            while (rS.size()<=K) rS.push_back(rS.back()^1);
            break;
        }

        A--;
        int v=rS.back();
        if (A>=DP[D-2]) {
            A-=DP[D-2];
            for (int k=0; k<3; k++) rS.push_back(v^1);
            D-=3;
        }
        else {
            rS.push_back(v); rS.push_back(v);
            D-=2;
        }
    }
    while (rT.size()<rS.size()) rT.push_back(rT.back()^1);
    return {rS, rT};
}

int Bruno(vector<si> U) {
    DP[0]=DP[1]=1; DP[2]=2;
    for (int i=3; i<=N; i++) DP[i]=DP[i-2]+DP[i-3]+1;

    int A=U[0]?0:accumulate(DP, DP+N, 0LL);
    int K=U.size()/2-1, S=0;

    for (int i=0; i<K; i++) A+=DP[i];
    int L=U[0], D=K;
    for (int i=1; i<U.size(); i++) {
        S+=U[i]?1:-1;
        if (S==2 || S==-2) {
            int tp=(S==2); A++;
            if (tp==L) D-=2; else A+=DP[D-2], D-=3;
            L=tp; S=0;
        }
    }

    return A;
}
