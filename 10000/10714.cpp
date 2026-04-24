#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

ll dp[2005][2005], sz[2005];

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){cin >> sz[i]; dp[i][i]=sz[i];}
    for(int t=1; t<n; t++){
        for(int s=0; s<n; s++){
            if(t%2){
                //dp[s][(s+t)%n]=max(dp[s][(s+t-1)%n], dp[(s+1)%n][(s+t)%n]);

                if(sz[(s+t)%n]>=sz[(s+n-1)%n]) dp[s][(s+t)%n]=max(dp[s][(s+t)%n], dp[s][(s+t-1)%n]);
                if(sz[(s+t+1)%n]<=sz[s]) dp[s][(s+t)%n]=max(dp[s][(s+t)%n], dp[(s+1)%n][(s+t)%n]);

            }
            else dp[s][(s+t)%n]=max(dp[s][(s+t-1)%n]+sz[(s+t)%n], dp[(s+1)%n][(s+t)%n]+sz[s]);
        }
    }
    ll mx=0;
    for(int i=0; i<n; i++){
        mx=max(mx, dp[i][(i+n-1)%n]);
    }
    cout << mx << endl;
    return 0;
}
