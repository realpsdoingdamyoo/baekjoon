#include <iostream>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, a, b, c;
signed main() {
    fastio;
    
    cin >> N >> a >> b;
    if(N>2) cin >> c;
    if(a>b) swap(a, b);
    int p=1;
    for(int i=1; i<b; i++) if(b%i==0) p=i;
    
    if(N==2 && a==1 && p==1) cout << "NO";
    else if(N==2) cout << "YES\n2\n" << a << " " << b;
    else cout << "YES\n3\n" << a << " " << b << " " << c;
 
    return 0;
}
