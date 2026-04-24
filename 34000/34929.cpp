#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, V[303030];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    
    for(int i=1; i<=N; i++) cin >> V[i];
    sort(V+1, V+N+1);
    cout << V[max(N-1, 1LL)] <<"\n";
    for(int i=1; i<N; i+=2){
        cout << V[i] << " " << V[i+1] << " " << V[i+2] << "\n";
        V[i+2]=V[i+1];
    }
    

    return 0;
}
