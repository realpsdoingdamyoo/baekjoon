#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, A[101], CC;

int W[100]={0, 6, 9, 7, 1, 2, 3, 10, 11, 4, 5, 8};

array<int, 3> ask() {
    if (1) {
        cout << "? ";
        for (int i=1; i<=N; i++) cout << A[i] << " "; cout << endl;
        array<int, 3> r; cin >> r[0] >> r[1] >> r[2];
        return {r[0], r[1], r[2]};
    }


    //for (int i=1; i<=N; i++) cout << W[A[i]] << " "; cout << " -> ";
    array<int, 3> ans={0, 0, 0};
    for (int i=1; i<=N; i++) {
        int H=inf;
        for (int j=i; j<=N; j++) {
            H=min(H, W[A[j]]);
            if ((j-i+1)*H>(ans[1]-ans[0]+1)*ans[2]) ans={i, j, H};
            else if ((j-i+1)*H==(ans[1]-ans[0]+1)*ans[2] && H>ans[2]) ans={i, j, H};
        }
    }
    //cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    if (CC++>1000) {
        for (int i=1; i<=N; i++) cout << W[i] << " "; cout << "\n";
        exit(0);
    }
    return ans;
}

signed main() {
    fastio;

    cin >> N;
    int T=10000, M=N-N/2; CC=0;
    for (int i=1; i<=N; i++) A[i]=i;

    while (T--) {
        array<int, 3> p=ask();
        if (p[0]==1) break;
        rotate(A+1, A+p[0], A+N+1);
    }

    int E=N;
    while (T--) {
        array<int, 3> p=ask();
        if (p[0]==1 && p[1]==M && p[2]==N/2+1) break;
        if (p[1]<=M) {
            for (int i=p[1]+2; i<=N; i++) {
                swap(A[p[1]+1], A[i]);
                array<int, 3> pp=ask();
                if (p[1]<pp[1]) break;
                swap(A[p[1]+1], A[i]);
            }
            E=N;
        }
        else {
            while (T--) {
                rotate(A+1, A+2, A+p[1]+1);
                p=ask();
                if (p[0]==1 && p[1]!=E) break;
            }
            E=p[1];
        }
    }

    for (int i=1, c=0; i<=M;) {
        if (c>M) {i++; c=0; continue;}
        swap(A[i], A[M]);
        swap(A[M], A[N]);
        array<int, 3> p=ask(); c++;
        if (p[0]==1 && p[1]==M-1) {
            if (p[2]!=N/2+1) {
                cout << "! " << A[N];
                return 0;
            }
        }
        else {
            rotate(A+M, A+M+1, A+N);
            swap(A[M], A[N]);
            swap(A[i], A[M]);
            continue;
        }
        swap(A[M], A[N]);
        swap(A[i], A[M]);
        i++; c=0;
    }

    return 0;
}
