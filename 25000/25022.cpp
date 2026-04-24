#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, M, DP[1010101], R;
int A[101010], B[101010], X[101010];
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

void print(priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> x) {
    while (x.size()) {
        cout << x.top()[0] << " " << x.top()[1] << " / ";
        x.pop();
    }
    cout << "\n";
}

vector<int> find_minimum_costs(signed n, vector<signed> a, vector<signed> b) {
    N=n; M=a.size(); vector<int> ans={0};
    for (int i=1; i<=M; i++) A[i]=a[i-1], B[i]=b[i-1];

    for (int i=1; i<=M; i++) pq.push({A[i]+B[i], i});

    for (int i=2; i<=2; i++) {
        int p=pq.top()[1]; pq.pop();
        X[p]++; R=max(A[p]*X[p]+B[p]+DP[X[p]], R);
        int q=pq.top()[1]; pq.pop();
        X[q]++; R=max(A[q]*X[q]+B[q]+DP[X[q]], R);
        DP[i]=R;
        pq.push({A[p]*(X[p]+1)+B[p]+DP[X[p]+1], p});
        pq.push({A[q]*(X[q]+1)+B[q]+DP[X[q]+1], q});
        ans.push_back(R);
    }

    for (int i=3; i<=N; i++) {
        int p=pq.top()[1]; pq.pop();
        X[p]++; R=max(A[p]*X[p]+B[p]+DP[X[p]], R);
        DP[i]=R;
        pq.push({A[p]*(X[p]+1)+B[p]+DP[X[p]+1], p});
        ans.push_back(R);
    }

    return ans;
}
