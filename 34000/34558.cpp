#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
const int M=1e6;
int P[M+10];

signed main(){
    fastio;

    for (int i=2; i<=M; i++) P[i]=1;
    for (int i=2; i<=M; i++) {
        if (P[i]) for (int j=i*2; j<=M; j+=i) P[j]=0;
        P[i]+=P[i-1];
    }

    cin >> N;
    for (int i=1; i<=N; i++) {
        int s, e; cin >> s >> e;
        int C=P[e]-P[s-1];
        if (C%2==0) {
            cout << "-1\n";
            continue;
        }

        int l=s, r=e;
        while (l<=r) {
            int m=l+r>>1;
            if (P[m]-P[s-1]>C/2) r=m-1;
            else l=m+1;
        }
        cout << l << "\n";
    }


    return 0;
}
