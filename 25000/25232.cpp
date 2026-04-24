#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

int N, K;

void solve2() {
    int AC=0;
    for (int i=1; i<=N; i++) {
        char a, b; cin >> a >> b;
        AC+=(a=='A');
    }
    cout << (AC*4>=N);
}

int C[1000], D[10000];

vector<int> P[5];
int TP[5]={1, 10, 100, 1000, 10000};

int erz(int x, int y) {
    if (x%10==y) return x/10;
    if (x/10%10==y) return x/100*10+x%10;
    if (x/100%10==y) return x/1000*100+x%100;
    return x%1000;
}

bool Awin(int W, vector<int> L) {
    if (W==1) return L[0]==1;
    int WC[5]={};
    for (int i : P[W]) WC[i/TP[W-1]]+=D[i];

    int R=L[0];
    for (int i : L) if (WC[i]<=WC[R]) R=i;
    for (int i : P[W]) D[erz(i, R)]+=D[i];
    for (int i=0; i<W; i++) if (L[i]==R) {
        L.erase(L.begin()+i); break;
    }
    
    return Awin(W-1, L);
}

signed main() {
    fastio;

    cin >> N >> K;
    if (K==2) {solve2(); return 0;}

    for (int i=1; i<=N; i++) {
        char a, b, c; cin >> a >> b >> c;
        C[(a-'A'+1)*100+(b-'A'+1)*10+(c-'A'+1)]++;
    }

    P[1]={1, 2, 3, 4};
    P[2]={12, 13, 14, 21, 23, 24, 31, 32, 34, 41, 42, 43};
    P[3]={123, 124, 132, 134, 142, 143, 213, 214, 231, 234, 241, 243, 312, 314, 321, 324, 341, 342, 412, 413, 421, 423, 431, 432};
    P[4]={1234, 1243, 1324, 1342, 1423, 1432, 2134, 2143, 2314, 2341, 2413, 2431, 3124, 3142, 3214, 3241, 3412, 3421, 4123, 4132, 4213, 4231, 4312, 4321};

    for (int i=0; i<=C[231]+C[213]; i++) {
        for (int j=0; j<=C[321]+C[312]; j++) {
            for (int k=1; k<=4; k++) for (int l : P[k]) D[l]=0;

            D[1234]=C[123];
            D[1324]=C[132];

            D[4231]=min(i, C[231]);
            D[2314]=C[231]-D[4231];
            D[4213]=max(i-C[231], 0LL);
            D[2134]=C[213]-D[4213];

            D[4321]=min(j, C[321]);
            D[3214]=C[321]-D[4321];
            D[4312]=max(j-C[321], 0LL);
            D[3124]=C[312]-D[4312];

            if (Awin(4, {1, 2, 3, 4})) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}
