#include "vision.h"
#include <bits/stdc++.h>
using namespace std;
int H, W;

int g(int x, int y){return W*x+y;}

void construct_network(int _H, int _W, int K) {
    H=_H; W=_W;

    map<int, vector<int>> X, Y;
    vector<int> A, B, VA, VB;

    for (int i=0; i<H; i++) for (int j=0; j<W; j++)
        X[i+j].push_back(g(i, j)), Y[i-j].push_back(g(i, j));

    for (int i=0; i<=H+W-2; i++) A.push_back(add_or(X[i]));
    for (int i=1-W; i<=H-1; i++) B.push_back(add_or(Y[i]));

    vector<int> As, Bs;
    for (int i=0; i<=H+W-2-K; i++) {
        vector<int> ns;
        for (int j=0; j<=H+W-2; j++) if (j<i || j>i+K) ns.push_back(A[j]);
        if (ns.size()) As.push_back(add_or(ns));
    }
    for (int i=0; i<=H+W-2-K; i++) {
        vector<int> ns;
        for (int j=0; j<=H+W-2; j++) if (j<i || j>i+K) ns.push_back(B[j]);
        if (ns.size()) Bs.push_back(add_or(ns));
    }

    vector<int> AC, BC;
    for (int i=0; i<=H+W-2-K; i++) AC.push_back(add_and({A[i], A[i+K]}));
    for (int i=0; i<=H+W-2-K; i++) BC.push_back(add_and({B[i], B[i+K]}));

    int a, b, c;
    if (As.size()) a=add_and({add_not(add_and(Bs)), add_or(AC)});
    else a=add_or(AC);
    if (Bs.size()) b=add_and({add_not(add_and(As)), add_or(BC)});
    else b=add_or(BC);
    c=add_and({add_or(AC), add_or(BC)});
    add_or({a, b, c});
}
