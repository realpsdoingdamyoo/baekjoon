#include <bits/stdc++.h>
using namespace std;

int solve(int N, int M, vector<int> F, vector<vector<int>> S) {
    vector<vector<int>> lnk(N); vector<int> U(N);
    for (int i=1; i<N; i++) lnk[F[i]].push_back(i);

    vector<priority_queue<int>> pq(M);

    int cn=0, ans=0;
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M; j++) pq[j].push(S[j][i]);
        while (pq[0].size()) {
            int x=pq[0].top(), fl=0;
            for (int j=0; j<M; j++) if (pq[j].top()!=x) fl=1;
            if (fl) break;
            for (int j=0; j<M; j++) pq[j].pop();
        }

        int p=S[0][i];
        for (int j : lnk[p]) cn+=!U[j];
        cn-=U[F[p]]; U[p]=1;

        if (cn==0 && pq[0].size()==0) ans++;
    }

    return ans;
}
