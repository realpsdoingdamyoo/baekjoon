#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, N, M;
int p[2][3030][3030];
array<int, 2> dp[2][3030][3030];
int cvl[2][3030][3030];
int mx[2][3030][3030];
array<int, 2> MX[2][3030][3030];

int case1(){
    int b[2]={0, 0};
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k : {0, 1})
        b[k]=max(b[k], dp[k][i][j][0]+dp[k][i][j][1]-1);
    return b[0]+b[1];
}

int case2(int t){
    int ret=0;

    for(int i=n-1; i>=0; i--) for(int j=n-1; j>=0; j--){
        ret=max(ret, cvl[t][i][j]+mx[t][i+1][j+1]);
        mx[t][i][j]=max(max(mx[t][i+1][j], mx[t][i][j+1]), cvl[t][i][j]);
    }
    return ret;
}

int case3(int t){
    int ret=0;

    for(int i=n-1; i>=0; i--) for(int j=n-1; j>=0; j--){
        ret=max(ret, cvl[t][i][j]+mx[t][i+dp[t][i][j][0]][0]);
        ret=max(ret, cvl[t][i][j]+mx[t][0][j+dp[t][i][j][1]]);
    }
    return ret;
}

int case4(int t){
    int ret=0;
    for(int i=1; i<n; i++) for(int j=1; j<n; j++){
        MX[t][i][j][0]=max(MX[t][i-1][j][0], cvl[t][i-1][j]);
        MX[t][i][j][1]=max(MX[t][i][j-1][1], cvl[t][i][j-1]);
        int val=MX[t][i][j][0]+MX[t][i][j][1];
        val-=min(dp[t][i][j][0], dp[t][i][j][1]);
        ret=max(ret, val);
    }

    return ret;
}

signed main(){
    fastio;

    cin >> N >> M; n=N+M+1>>1;
    for(int i=0; i<N; i++){
        string s; cin >>s;
        for(int j=0; j<M; j++)
            p[i+j&1][(N+M-i-j-2)>>1][N+j-i-1>>1]=s[j]-'0';
    }

    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
        for(int k=0; k<2; k++)
            dp[k][i][j]={p[k][i][j], p[k][i][j]};

    for(int i=n-1; i>=0; i--) for(int j=n-1; j>=0; j--)
        for(int k=0; k<2; k++)
            if(p[k][i][j])
                dp[k][i][j][0]+=dp[k][i+1][j][0], dp[k][i][j][1]+=dp[k][i][j+1][1],
                cvl[k][i][j]=max(dp[k][i][j][0]+dp[k][i][j][1]-1, 0LL);

    int ret=0;
    ret=max(ret, case1());
    ret=max(ret, case2(0));
    ret=max(ret, case2(1));
    ret=max(ret, case3(0));
    ret=max(ret, case3(1));
    ret=max(ret, case4(0));
    ret=max(ret, case4(1));
    cout << ret;

    return 0;
}
