#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;
 
signed main(){
    fastio;
 
    int C; cin >> C;
    if (C==0) {
        int N, M, ADJ[50][50]={};
        cin >> N >> M;
        for (int i=1; i<=M; i++) {
            int a, b; cin >> a >> b;
            if (a>b) swap(a, b);
            ADJ[a][b]=1;
        }
 
        vector<int> bit;
        for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++)
            bit.push_back(ADJ[i][j]);
 
        while (bit.size()%10) bit.push_back(0);
 
        cout << bit.size()/10 << "\n";
 
        for (int i=0; i<bit.size(); i+=10) {
            int a=0, b=0;
            for (int j=i; j<i+5; j++) a=a*2+bit[j];
            for (int j=i+5; j<i+10; j++) b=b*2+bit[j];
            cout << max(a+1, 1LL) << " " << max(b+1, 1LL) << "\n";
        }
    }
    else {
        int N, Q;
        cin >> N >> Q;
 
        vector<int> bit;
        for (int i=1; i<=Q; i++) {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            for (int j=4; j>=0; j--) bit.push_back(!!(a&(1<<j)));
            for (int j=4; j>=0; j--) bit.push_back(!!(b&(1<<j)));
        }
 
        int M=0;
        for (int i : bit) M+=i;
        cout << M << "\n";
 
        int p=0;
        for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) {
            if (bit.size()>p && bit[p]) cout << i << " " << j << "\n";
            p++;
        }
    }
 
 
    return 0;
}
