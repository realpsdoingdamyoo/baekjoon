#include <bits/stdc++.h>
using namespace std;

bool reversal(int N, int M, vector<string> P) {
    for (int i=0; i<N-M; i++) for (int j=0; j<N-M; j++)
        if ((P[i][j]=='O')^(P[i+M][j]=='O')^(P[i][j+M]=='O')^(P[i+M][j+M]=='O')) return false;
    return true;
}
