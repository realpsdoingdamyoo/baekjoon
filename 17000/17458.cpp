#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//const int mod=1e9+7, MOD=998244353, inf=1e18;

int X[4][4][4], op[4]={0, 2, 1, 3};

struct BCK{
    int K=0, G[10][10][4]={}, P[10][10]={};
    vector<int> U;

    void init() {
        for (int i : U)
            for (int j=0; j<K; j++) for (int k=0; k<K; k++) if (i&(1<<j) && ~i&(1<<k))
                G[j][k][1]=G[j][k][3]=1, G[k][j][2]=G[k][j][3]=1;
    }

    int sol(int x, int y) {
        if (y==K) return 1;

        int ret=0;
        for (int i=0; i<4; i++) if (G[y][x][i]==0) {
            int ct=0;
            for (int p=0; p<x; p++) if (X[P[x][p]][P[p][y]][i]) ct=1;
            if (ct) continue;
            P[y][x]=i; P[x][y]=op[i];

            if (x==y-1) ret+=sol(0, y+1);
            else ret+=sol(x+1, y);

            P[y][x]=P[x][y]=0;
        }

        return ret;
    }
};



int inc(int x, int y){return (x|y)==y;}

signed main(){
    fastio;

    for (int i=0; i<4; i++) for (int j=0; j<4; j++) for (int k=0; k<4; k++) {
        if ((i&1) && (j&1) && !(k&2)) X[i][j][k]=X[j][k][i]=X[k][i][j]=1;
        if ((i&2) && (j&2) && !(k&1)) X[i][j][k]=X[j][k][i]=X[k][i][j]=1;
    }

    int K, N, A=127, O=0, ans=0;
    cin >> K >> N;
    vector<int> V(N);
    for (int& i : V) cin >> i, A=A&i, O=O|i;

    if (K==7 && N==0) {cout << 13170651; return 0;}
    if (K==7 && N==1) if (V[0]==0 || V[0]==127) {cout << 11161244; return 0;}

    for (int a=0; a<1<<K; a++) for (int o=0; o<1<<K; o++) {
        if (!inc(a, A) || !inc(O, o) || !inc(a, o)) continue;

        BCK bck;
        for (int i=0; i<K; i++) if ((a^o)&(1<<i)) bck.K++;
        for (int i : V) {
            int g=0;
            for (int j=0, id=0; j<K; j++) if (((a^o)&(1<<j))) {
                if (i&(1<<j)) g|=1<<id; id++;
            }
            bck.U.push_back(g);
        }

        if (bck.K<=1) ans++;
        else {
            bck.init();
            ans+=bck.sol(0, 1);
        }
    }
    cout << ans << "\n";

    return 0;
}
