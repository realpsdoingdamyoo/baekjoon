#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, Q, T=100000;
int A[101010], S[101010], C[101010], X[101010];
priority_queue<array<int, 2>> pq;
vector<int> W[101010], O[101010], U[101010];
int R[101010];
priority_queue<int> pq2;

int Z[101010];

signed main(){
    fastio;

    cin >> N >> M >> Q;
    for (int i=1; i<=N; i++) {
        cin >> A[i] >> S[i] >> C[i] >> X[i];
        if (X[i]==0) pq.push({A[i]+S[i], i});
        else W[min((C[i]-1)/X[i]+1, T)].push_back(i);
    }

    vector<int> pss;
    for (int t=T; t>=1; t--) {
        for (int i : W[t]) pq.push({A[i]+S[i], i});
        for (int i : pss) pq.push({A[i], i}); pss.clear();

        for (int i=1; i<=M && pq.size(); i++) {
            int cs=pq.top()[0], id=pq.top()[1]; pq.pop();
            pq2.push(-cs); R[T]+=cs; cs=A[id]; C[id]--;
            Z[id]++;

            if (X[id]==0) {if (C[id]) pq.push({cs, id});}
            else if ((C[id]+X[id]-1)/X[id]<t) pss.push_back(id);
            else pq.push({cs, id});
        }
    }

    for (int t=T-1; t>=1; t--) {
        for (int i : O[t+1]) pq2.push(i);
        R[t]=R[t+1];
        while (pq2.size()>M*t) {
            R[t]+=pq2.top(); pq2.pop();
        }
    }

    for (int i=1; i<=Q; i++) {
        int x; cin >> x;
        cout << R[x] << "\n";
    }


    return 0;
}
