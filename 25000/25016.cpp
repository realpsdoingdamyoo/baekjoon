#include <bits/stdc++.h>
using namespace std;
int N=1;
struct Node {
    array<int, 3> D={}; int P=0, S=0;
    int getD() {return max(D[2]-1, D[1]);}
    int getDS() {return max(D[2]+D[1]-1, D[1]+D[0]);}
} node[505050];

void init() {}

void update(int p, int x) {
    int pD=node[p].getD();
    for (int& i : node[p].D) if (i==x-1) {i=x; break;}
    sort(node[p].D.begin(), node[p].D.end());
    node[p].S=max(node[p].S, node[p].getDS());
    int C=(node[node[p].P].S<node[p].S);
    if (p==1) return;
    node[node[p].P].S=max(node[node[p].P].S, node[p].S);
    if (C || pD!=node[p].getD()) update(node[p].P, node[p].getD()+1);
}
void observation(int p) {node[++N].P=p; update(p, 1);}
int analyze(int r) {return node[r].S;}
