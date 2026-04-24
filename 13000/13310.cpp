#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, T;
array<int, 2> P[30303];
array<int, 2> V[30303];

struct far {
    array<int, 2> v[30303];
    vector<array<int, 2>> U, D;

    int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
        return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
    }

    int frd() {
        U=D={};
        sort(v+1, v+N+1);
        for (int i=1; i<=N; i++) {
            while (U.size()>=2 && ccw(U[U.size()-2], U[U.size()-1], v[i])<=0) U.pop_back(); U.push_back(v[i]);
            while (D.size()>=2 && ccw(D[D.size()-2], D[D.size()-1], v[i])>=0) D.pop_back(); D.push_back(v[i]);
        }

        vector<array<int, 2>> C=U; C.pop_back();
        reverse(D.begin(), D.end()); D.pop_back();
        for (array<int, 2> i : D) C.push_back(i);

        int M=C.size(), j=0, ans=0, cnt=0;
        for (int i=0; i<M; i++) {
            if (i==j) j=(j+1)%M;
            while (1) {
                array<int, 2> I={C[(i+1)%M][0]-C[i][0], C[(i+1)%M][1]-C[i][1]};
                array<int, 2> J={C[(j+1)%M][0]-C[j][0], C[(j+1)%M][1]-C[j][1]};
                ans=max(ans, (C[i][0]-C[j][0])*(C[i][0]-C[j][0])+(C[i][1]-C[j][1])*(C[i][1]-C[j][1]));
                cnt++;
                if (ccw(I, {0, 0}, J)<0) j=(j+1)%M; else break;
            }
        }
        return ans;
    }

    int dist(int t) {
        for (int i=1; i<=N; i++) v[i][0]=P[i][0]+V[i][0]*t;
        for (int i=1; i<=N; i++) v[i][1]=P[i][1]+V[i][1]*t;
        return frd();
    }
} F;

signed main(){
    fastio;

    cin >> N >> T;
    for (int i=1; i<=N; i++) cin >> P[i][0] >> P[i][1] >> V[i][0] >> V[i][1];

    int s=0, e=T-1;
    while (s<=e) {
        int m=s+e>>1;
        if (F.dist(m)<=F.dist(m+1)) e=m-1; else s=m+1;
    }
    cout << s << "\n" << F.dist(s);

    return 0;
}
