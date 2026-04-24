#include "stub.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

const int C=52;

void Swap(int x, int y){
    doSwap(x, y);
}

void swapCards(int cd[], int S, int T){
    int vis[C], cnt=0;
    vector<vector<int>> cyc;

    for(int i=0; i<C; i++){
        if(vis[i]) continue;

        cyc.push_back({i}); vis[i]=1;
        for(int j=cd[i]; j!=i; j=cd[j]) cyc.back().push_back(j), vis[j]=1;
    }

    for(vector<int> v : cyc){
        for(int i=1; i<=(v.size()-1)/T; i++){
            Swap(v[i*T-1], v.back());
        }
    }
}

void guessCard(int S, int T, int tar){
    int tt=tar;
    while(T--){
        tar=guess(tar);
        if(tar==tt) break;
    }
}
