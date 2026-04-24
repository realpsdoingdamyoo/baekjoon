#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, M, A[101010], B[101010], DP[101010]={-inf};
char ans[101010];

int in(int s, int e) {return s<=e && lower_bound(B+1, B+M+1, s)!=upper_bound(B+1, B+M+1, e);}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=M; i++) cin >> B[i]; B[0]=-1;

    int s=0, e=1e9;
    while (s<=e) {
        int K=s+e>>1, fl=0;

        for (int i=1; i<=N; i++) {
            if (!in(DP[i-1]+1, A[i]-1)) DP[i]=A[i]+K;
            else if (in(DP[i-1]+1, A[i]-K-1)) {fl=1; break;}
            else {
                int p=*(lower_bound(B+1, B+M+1, A[i]-K)-1);
                if (i>1 && (DP[i-2]>=p || p==-1)) DP[i]=max(A[i-1]+K, A[i]);
                else DP[i]=A[i];
            }
        }
        if (fl || DP[N]<B[M]) s=K+1; else e=K-1;
    }
    if (s==1e9+1) {cout << "-1"; return 0;}

    int K=s;
    for (int i=1; i<=N; i++) {
        if (!in(DP[i-1]+1, A[i]-1)) DP[i]=A[i]+K;
        else {
            int p=*(lower_bound(B+1, B+M+1, A[i]-K)-1);
            if (i>1 && (DP[i-2]>=p || p==-1)) DP[i]=max(A[i-1]+K, A[i]);
            else DP[i]=A[i];
        }
    }

    for (int i=N; i>=1; i--) {
        if (!in(DP[i-1]+1, A[i]-1)) ans[i]='R';
        else {
            int p=*(lower_bound(B+1, B+M+1, A[i]-K)-1);
            if (i>1 && (DP[i-2]>=p || p==-1)) {
                ans[i]='L'; ans[i-1]='R'; i--;
            }
            else ans[i]='L';
        }
    }
    cout << K << "\n" << (ans+1);


    return 0;
}
