#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

vector<array<int, 4>> vec={{0, 0, 0, 0}};
vector<array<int, 4>> ret;

int C[55][55];

signed main(){
    fastio;

    for (int i=0; i<=50; i++) for (int j=0; j<=50; j++) {
        if (i*j==0) C[i][j]=1; else C[i][j]=C[i-1][j]+C[i][j-1];
    }

    for (int d : {1, 2, 3, 4, 6, 12}) {
        for (int k=0; 12+k*d<=50; k++) {
            if (C[12/d][k]>50) continue;
            vec.push_back({d, k, 12+d*k, C[12/d][k]});
        }
    }

    int N; cin >> N;

    int M=vec.size();

    for (int i=0; i<M; i++) {
        for (int j=i; j<M; j++) {
            for (int k=j; k<M; k++) {
                for (int l=k; l<M; l++) {
                    int S=vec[i][2]+vec[j][2]+vec[k][2]+vec[l][2];
                    int R=vec[i][3]+vec[j][3]+vec[k][3]+vec[l][3];
                    if (S<=50 && R==N) {
                        ret.push_back(vec[i]);
                        ret.push_back(vec[j]);
                        ret.push_back(vec[k]);
                        ret.push_back(vec[l]);
                        i=j=k=l=M+1;
                    }
                }
            }
        }
    }

    int p=0;
    for (array<int, 4> i : ret) {
        int d=i[0], k=i[1];
        if (d==0) continue;
        vector<int> np;
        for (int j=0; j<k; j++) np.push_back(0);
        for (int j=0; j<12/d; j++) np.push_back(1);

        do {
            for (int j=0; j<12/d+k; j++) if (np[j]) {
                for (int l=j*d; l<j*d+d; l++) cout << p+l << " ";
            }
            cout << '\n';
        }while (next_permutation(np.begin(), np.end()));
        p+=12+k*d;
    }

    return 0;
}
