#include "souvenirs.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int N;
long long buy[101], PR[101];

pair<vector<int>, long long> Transaction(long long M) {
    pair<vector<int>, long long> ret= transaction(M);
    for (int i : ret.first) buy[i]++; return ret;
}

void Find(long long X) {
    pair<vector<int>, long long> tr=Transaction(X);

    X-=tr.second;
    while (tr.first.size()>1) {
        int tp=tr.first.back(), SZ=tr.first.size(); tr.first.pop_back();
        if (PR[tp]){X-=PR[tp]; continue;}
        long long C=X/SZ;
        for (int i=0; i<tp; i++) if (PR[i]) C=min(C, PR[i]-1);
        Find(C);
        X-=PR[tp];
    }
    PR[tr.first[0]]=X;
    for (int i=tr.first[0]+1; i<N; i++) if (!PR[i]) Find(PR[i-1]-1);
}

void buy_souvenirs(int n, long long P0) {
    N=n;
    Find(P0-1);
    for (int i=1; i<n; i++) while (buy[i]<i) Transaction(PR[i]);
}
