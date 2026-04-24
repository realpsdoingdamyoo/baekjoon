#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main(){
    fastio;

    int n; cin >> n;
    if(n<=2){cout << "NO"; return 0;}

    cout << "YES\n";
    if(n%4==0){
        for(int i=0; i<n/2; i++) cout << i%2+1 << " " << i*2+1 << "\n";
        for(int i=0; i<n/2; i++) cout << i%2+1 << " " << (n/2-i)*2 << "\n";
        for(int i=1; i<n/2; i++) cout << 2-i%2 << " " << i*2+1 << "\n";
        for(int i=0; i<n/2; i++) cout << 2-i%2 << " " << (n/2-i)*2 << "\n";
        cout << "2 1\n";
    }
    else if(n%4==1){
        cout << "1 1\n";
        for(int i=0; i<n/2; i++) cout << (i%2^1)+1 << " " << i*2+2 << "\n";
        for(int i=0; i<n/2; i++) cout << (i%2^1)+1 << " " << (n/2-i)*2+1 << "\n";
        cout << "2 1\n";
        for(int i=0; i<n/2; i++) cout << (i%2)+1 << " " << i*2+2 << "\n";
        for(int i=0; i<n/2; i++) cout << (i%2)+1 << " " << (n/2-i)*2+1 << "\n";
    }
    else if(n%4==2){
        for(int i=0; i<n/2; i++) cout << i%2+1 << " " << i*2+1 << "\n";
        for(int i=0; i<n/2; i++) cout << 2-i%2 << " " << (n/2-i)*2 << "\n";
        for(int i=1; i<n/2; i++) cout << 2-i%2 << " " << i*2+1 << "\n";
        for(int i=0; i<n/2; i++) cout << i%2+1 << " " << (n/2-i)*2 << "\n";
        cout << "2 1\n";
    }
    else if(n%4==3){
        for(int i=0; i<=n/2; i++) cout << i%2+1 << " " << i*2+1 << "\n";
        for(int i=0; i<n/2; i++) cout << i%2+1 << " " << (n/2-i)*2 << "\n";
        for(int i=0; i<=n/2; i++) cout << 2-i%2 << " " << i*2+1 << "\n";
        for(int i=0; i<n/2; i++) cout << 2-i%2 << " " << (n/2-i)*2 << "\n";
    }

    return 0;
}
