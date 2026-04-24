#include <bits/stdc++.h>
using namespace std;
#define int long long

int k,t,n,i,j;
vector<int> dp, DP;

void solve(){
cin>>n;
for(i=0;i<k;i++) dp[i]=0;
int ddp=0,ddpx=1;
for(i=47;i>=0;i--){
int x=(1LL<<i)%k;
for(j=0;j<k;j++) DP[j]=dp[j]-dp[(j-x+k)%k];
if((n*k)&(1LL<<i)){DP[ddp]+=ddpx;ddp=(ddp+x)%k;ddpx*=-1;}          
swap(dp,DP);
}
cout<<1-dp[0]-(!ddp)*ddpx<<"\n";
}

signed main(){
cin >> k >> t;
while(~k&1) k>>=1;
dp.resize(k); DP.resize(k);
while(t--) solve();
}
