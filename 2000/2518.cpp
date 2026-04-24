#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9, bnd=1e10;

int n, k;

int dist(int a, int b){
    if(a>b) swap(a, b);
    return min(b-a, a-b+n);
}

vector<vector<array<int, 3>>> tmp(303, vector<array<int, 3>>(303));
vector<vector<vector<array<int, 3>>>> dp(303);
int s[3], x[3][303];

signed main(){
    fastio;

    cin >> n; k=n/3;
    for(int i=0; i<3; i++){
        cin >> s[i];
        for(int j=1; j<=s[i]; j++){
            cin >> x[i][j];
            x[i][j]=(x[i][j]-1-i*k+n)%n+1;
        }
    }

    array<int, 3> i;
    x[0][0]=x[1][0]=x[2][0]=1;

    for(i[0]=0; i[0]<=s[0]; i[0]++){
        dp[i[0]]=tmp;
        for(i[1]=0; i[1]<=s[1]; i[1]++){
            for(i[2]=0; i[2]<=s[2]; i[2]++){
                for(int p=0; p<3; p++){
                    dp[i[0]][i[1]][i[2]][p]=inf*!!(i[0]+i[1]+i[2]);
                }
            }
        }
        for(i[1]=0; i[1]<=s[1]; i[1]++){
            for(i[2]=0; i[2]<=s[2]; i[2]++){
                for(int p=0; p<3; p++){
                    for(int q=0; q<3; q++){
                        array<int, 3> j=i; j[p]--;
                        if(j[p]<0) continue;
                        dp[i[0]][i[1]][i[2]][p]=min(dp[i[0]][i[1]][i[2]][p], dp[j[0]][j[1]][j[2]][q]+dist(x[q][j[q]], x[p][i[p]]));
                    }
                }
            }
        }
        if(i[0]>=1) dp[i[0]-1].clear();
    }
    cout << min(dp[s[0]][s[1]][s[2]][0], min(dp[s[0]][s[1]][s[2]][1], dp[s[0]][s[1]][s[2]][2]));

    return 0;
}
