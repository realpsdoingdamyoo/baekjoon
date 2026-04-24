#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, M;
string S[110];
vector<vector<int>> ans;
signed main() {
    fastio;
    
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> S[i], S[i]+='O';
    for(int i=0; i<=M; i++) S[N+1]+='O';
    
    for(int i=0; i<M; i++){
        for(int j=1; j<=N; j++){
            if(S[j][i]=='X'){
                char& c=(N==1?S[j][i+1]:S[j+1][i]);
                if(c=='X') ans.push_back({2, i*N+j, i*N+j+1}), c='O';
                else ans.push_back({1, i*N+j});
            }
        }
    }
    cout << ans.size() << "\n";
    for(vector<int> i : ans){
        for(int j : i) cout << j << " ";
        cout << "\n";
    }
    
    return 0;
}
