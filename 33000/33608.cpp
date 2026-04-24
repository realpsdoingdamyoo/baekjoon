#include <bits/stdc++.h>
using namespace std;
#include "evolution2.h"


vector<int> lnk[10101], vec[10101];
int id[10101];

void push(int x, int s, int e, vector<int> tp) {
    if (tp.size()==0) return;
    if (s==e) {for (int i : tp) id[i]=s; return;}
    int tm=tp.size()/2;
    int l=s, r=e;
    while (l<=r) {
        int m=l+r>>1;
        if (m!=e && compare(vec[x][m], tp[tm])) l=m+1;
        else r=m-1;
    }
    id[tp[tm]]=l;
    push(x, s, l, vector(tp.begin(), tp.begin()+tm));
    push(x, l, e, vector(tp.begin()+tm+1, tp.end()));

}

void mrg(int x, int y) {
    push(x, 0, vec[x].size(), vec[y]);

    vector<int> nwv;
    for (int i=0, j=0; i<=vec[x].size(); i++) {
        while (j<vec[y].size() && id[vec[y][j]]==i) nwv.push_back(vec[y][j]), j++;
        if (i!=vec[x].size()) nwv.push_back(vec[x][i]);
    }
    for (int i=0; i<nwv.size(); i++) id[nwv[i]]=i;
    swap(nwv, vec[x]);
}

void DFS(int p) {
    if (lnk[p].size()==0) {vec[p]={p}; return;}
    for (int i : lnk[p]) DFS(i);
    sort(lnk[p].begin(), lnk[p].end(), [&](int a, int b){return vec[a].size()>vec[b].size();});

    for (int i=1; i<lnk[p].size(); i++) mrg(lnk[p][0], lnk[p][i]);
    swap(vec[p], vec[lnk[p][0]]);
    vec[p].insert(vec[p].begin(), p);
    for (int i=0; i<vec[p].size(); i++) id[vec[p][i]]=i;
}

vector<int> recover(int N, vector<int> U, vector<int> V) {
    for (int i=0; i<N; i++) lnk[i].clear(), vec[i].clear(), id[i]=0;
    for (int i=0; i<N-1; i++) lnk[U[i]].push_back(V[i]);

    DFS(0);
    vector<int> ret;
    for (int i=0; i<N; i++) ret.push_back(id[i]);
    return ret;
}
