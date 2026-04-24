#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;

int main(){
    fastio;
    string a, b;
    cin >> a >> b;
    int s=0;
    for(int i=0; i<a.length(); i++) s+=(a[i]=='1');
    s+=s%2;
    for(int i=0; i<b.length(); i++) s-=(b[i]=='1');
    if(s>=0) cout << "VICTORY\n";
    else cout << "DEFEAT\n";
    return 0;
}
