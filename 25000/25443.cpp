#include"islands.h"

#include <bits/stdc++.h>
using namespace std;

int N, M, X;
set<array<int, 2>> lnk[101010];
vector<int> rnk[101010], st;
int odg[101010], O[101010];
array<int, 2> G[101010];
vector<int> ans;

void Fnd() {
    for (int i=1; i<=N; i++) O[i]=0;
    int p=X;
    while (!O[p]) O[p]=1, ans.push_back(G[p][1]), p=G[p][0];

    vector<int> tp;
    for (int i=X; i!=p;) tp.push_back(G[i][1]), i=G[i][0];
    reverse(tp.begin(), tp.end());

    for (int i : tp) ans.push_back(i);
    array<int, 2> prv=G[p];
    for (int i=p;;) {
        swap(i, prv[0]), swap(G[i], prv);
        if (i==p) break;
    }
}

variant<bool, vector<int>> find_journey(int _N, int _M, vector<int> U, vector<int> V) {
    N=_N; M=_M;

    for (int i=0; i<M; i++) {
        U[i]++; V[i]++;
        lnk[U[i]].insert({V[i], i});
        rnk[V[i]].push_back(U[i]); odg[U[i]]++;
    }

    vector<int> st; X=1;
    for (int i=1; i<=N; i++) if (odg[i]==0) st.push_back(i);
    while (st.size() || lnk[X].size()<=1) {
        int p;
        if (st.size()) {p=st.back(); st.pop_back(); if (p==X) return false;}
        else p=X, ans.push_back((*lnk[X].begin())[1]), X=(*lnk[X].begin())[0];

        O[p]=1;
        for (int i : rnk[p]) if (!O[i]) {
            lnk[i].erase(lnk[i].lower_bound({p, 0}));
            if (!--odg[i]) st.push_back(i);
        }
    }


    vector<int> tp=ans;
    for (int i=1; i<=N; i++) G[i]=*lnk[i].begin();
    array<int, 2> sec=*prev(lnk[X].end());

    for (int i=0; i<12; i++) Fnd(), swap(G[X], sec);
    reverse(tp.begin(), tp.end());
    for (int i : tp) ans.push_back(i);

    return ans;
}
