#include "books.h"

#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//const int mod=1e9+7, MOD=998244353, inf=2e18;

long long P[20], S[20], SP[20], SS[20];

void solve(int N, int K, long long A, int tmp) {
    vector<int> ans(K);

    int s=1, e=N;
    while (s<e) {
        int m=s+e>>1;
        if (skim(m)>=A) e=m; else s=m+1;
    }

    for (int i=1; i<=K; i++) P[i]=skim(i), SP[i]=SP[i-1]+P[i];

    long long X=skim(s);
    if (X>=A) {
        X+=SP[K-1];
        if (X<=A*2) {
            for (int i=0; i<K-1; i++) ans[i]=i+1;
            ans[K-1]=s;
            answer(ans);
        }
        s--;
    }

    if (s<K) impossible();

    for (int i=1; i<=K; i++) S[i]=skim(s-i+1), SS[i]=SS[i-1]+S[i];

    for (int k=K; k>=0; k--) {
        X=SP[k]+SS[K-k];
        if (X>=A && X<=A*2) {
            int p=0;
            for (int i=1; i<=k; i++) ans[p++]=i;
            for (int i=1; i<=K-k; i++) ans[p++]=s-i+1;
            answer(ans);
        }
    }
    impossible();
}
