#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int c[101010];
array<int, 2> dp[151515];

signed main(){
	fastio;

	int n, m; cin >> n >> m;
	vector<int> u(n-m);
	for(int i=1; i<=n; i++) c[i]=-1;
	for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        c[b]=a;
	}
	for(int& i : u) cin >> i;

	int s=1, e=1e10;
	while(s<=e){
        int N=n+n/2, p=s+e>>1;
        for(int i=1; i<=N; i++){
            if(i<=n){
                if(c[i]==-1) dp[i]={1, 0};
                else if(c[i]<p) dp[i]={0, -inf};
                else dp[i]={-inf, 0};
            }
            else{
                int x=(i-n)*3-2, y=(i-n)*3-1, z=(i-n)*3;
                dp[i]={-inf, -inf};
                dp[i][0]=max(dp[i][0], dp[x][0]+dp[y][0]+dp[z][0]);
                dp[i][0]=max(dp[i][0], dp[x][0]+dp[y][0]+dp[z][1]);
                dp[i][0]=max(dp[i][0], dp[x][0]+dp[y][1]+dp[z][0]);
                dp[i][0]=max(dp[i][0], dp[x][1]+dp[y][0]+dp[z][0]);

                dp[i][1]=max(dp[i][1], dp[x][0]+dp[y][1]+dp[z][1]);
                dp[i][1]=max(dp[i][1], dp[x][1]+dp[y][0]+dp[z][1]);
                dp[i][1]=max(dp[i][1], dp[x][1]+dp[y][1]+dp[z][0]);
                dp[i][1]=max(dp[i][1], dp[x][1]+dp[y][1]+dp[z][1]);
            }
        }

        int cnt=0;
        for(int i : u) if(i<p) cnt++;
        if(cnt<=dp[N][1]) s=p+1;
        else e=p-1;
	}
	cout << e;

    return 0;
}
