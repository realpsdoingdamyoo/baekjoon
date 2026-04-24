#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

signed main(){
    fastio;

    int a, b, c=0; cin >> a >> b;
    if (a==6) if (30<=b) c=1;
    if (a==7 || a==8) c=1;
    if (a==9 || a==10 || a==11 || a==12) if (b==0 || 50<=b) c=1;
    if (a==13) if (b<=50) c=1;
    if (a==14 || a==15) if (40<=b && b<=50) c=1;
    if (a==16) if (40<=b) c=1;
    if (17<=a && a<=21) c=1;
    if (a==22) if (b<=50) c=1;

    cout << (c?"Yes":"No");

    return 0;
}
