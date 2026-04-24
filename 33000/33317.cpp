#include "grid_encoding.h"
#include <bits/stdc++.h>
using namespace std;

void send(vector<vector<int>> A) {
    int N=A.size();
    vector<vector<array<int, 3>>> NA(N, vector<array<int, 3>>(N));
    vector<int> X(N, 0), Y(N, 0);
    for (int i=0; i<N; i++) for (int j=0; j<N; j++)
        NA[i][j]={A[i][j], i, j}, X[i]+=A[i][j], Y[j]+=A[i][j];

    sort(NA.begin(), NA.end(), [&](vector<array<int, 3>> a, vector<array<int, 3>> b) {return X[a[0][1]]>X[b[0][1]];});
    for (int i=0; i<N; i++) sort(NA[i].begin(), NA[i].end(), [&](array<int, 3> a, array<int, 3> b){return Y[a[2]]<Y[b[2]];});

    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        if (NA[i][j][0]==0 && (i==0 || NA[i-1][j][0]==1)) select(NA[i][j][1], NA[i][j][2]);
        if (NA[i][j][0]==1 && (j==0 || NA[i][j-1][0]==0)) select(NA[i][j][1], NA[i][j][2]);
    }
}

vector<vector<int>> reconstruct(vector<vector<int>> B) {
    int N=B.size();
    vector<int> deg(N*2), v(N*2);
    queue<int> q;
    vector<array<int, 2>> z;

    for (int i=0; i<N; i++) for (int j=0; j<N; j++) if (B[i][j]!=-1) {
        if (B[i][j]==1) z.push_back({i, j+N});
        else z.push_back({j+N, i});
        deg[z.back()[0]]++;
    }

    int cnt=1, h=0, t=0;
    for (int i=0; i<N*2; i++) if (!deg[i]) v[i]=cnt, q.push(i);

    while (q.size()) {
        int sz=q.size(); cnt++;
        while (sz--) {
            int x=q.front(); q.pop();
            for (array<int, 2> i : z) {
                if (x==i[1]) {
                    if (!--deg[i[0]]) q.push(i[0]), v[i[0]]=cnt;
                }
            }
        }
    }
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) B[i][j]=(v[i]>v[N+j]);

    return B;
}
