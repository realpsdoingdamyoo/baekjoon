#include "island.h"
#include <bits/stdc++.h>
using namespace std;

void construct_two_trees(int N, vector<int> U, vector<int> V) {
    vector<int> tl(N); iota(tl.begin()+1, tl.end(), 0); tl[0]=N-1;
    for (int i=0; i<N-3; i++) tl[U[i]]=min(tl[U[i]], V[i]), tl[V[i]]=min(tl[V[i]], U[i]);
    add_vertex(0, 1, tl[0]);
    vector<array<int, 2>> A1={{N, tl[0]}}, A2={{0, N}, {N, 1}, {N-1, 0}};
    for (int i=0; i<N-3; i++) ((tl[U[i]]==V[i] || tl[V[i]]==U[i])?A1:A2).push_back({U[i], V[i]});
    for (int i=0; i<N-1; i++) (tl[i+1]==i?A1:A2).push_back({i, i+1});

    report(A1); report(A2);
}
