#include "liar.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

vector<int> game(int k, int n) {
    vector<int> u, res={0};
    for (int i=1; i<=(1<<k)+1; i++) u.push_back(i);
    for (int i=(1<<k)+2; i<=n; i++) res.push_back(i);
    while (res.size()) {
        for (int i=1; i<=k+1; i++) {
            if (ask({u.back()})) break;
            if (i==k+1) u.pop_back();
        }
        if (u.size()==1<<k) {
            u.push_back(res.back());
            res.pop_back();
            continue;
        }

        int del=0;
        for (int i=0; i<k; i++) {
            vector<int> v;
            for (int j=0; j<(1<<k); j++) {
                if (j&(1<<i)) v.push_back(u[j]);
            }
            if (!ask(v)) del+=1<<i;
        }
        u.erase(u.begin()+del);
        u.push_back(res.back());
        res.pop_back();
    }
    u.pop_back();
    return u;
}
