#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, A[110];
vector<int> ans;

void go(int x){
    ans.push_back(x);
    for(int i=x; i>1; i--) swap(A[i], A[i-1]), swap(A[i+1], A[i]);
}
void solve(int K){
    if(K==0) return;
    if(K==2 && A[1]==2){
        cout << "NO"; exit(0);
    }
    if(A[K]==K) {solve(K-1); return;}
    if(A[1]==K){
        if(K%2==0){
            go(2); go(2);
        }
    }
    else{
        for(int i=1; i<=K; i++) if(A[i]==K){
            if(K%2==1) go(i);
            else go(i-1);
            break;
        }
    }
    for(int i=K; i>2; i-=2) go(K-1);
    
    solve(K-1);
}

signed main() {
    fastio;
    
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    solve(N);
    
    cout << "YES\n" << ans.size() << "\n";
    for(int i : ans) cout << i << " ";
    
    return 0;
}
