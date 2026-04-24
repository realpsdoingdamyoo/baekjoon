#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N;
string S;

signed main() {
    fastio;
    
    cin >> S; N=S.size();
    reverse(S.begin(), S.end());
    
    string p="SKA";
    if(N%3==0) p="ASK";
    if(N%3==1) p="KAS";
    int ans=0;
    for(int i=0, g=0, j=0; i<N; i++){
        if(S[i]==p[g] && i%2==j) g=(g+1)%3, ans++, j^=1;
    }
    
    cout << (N-ans)*2;
    
    return 0;
}
