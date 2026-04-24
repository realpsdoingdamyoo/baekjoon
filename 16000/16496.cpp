#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define vcout; for(int i=0; i<v.size(); i++) cout << v[i] << " ";
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool cmp(string a, string b){
    return a+b>b+a;
}

int main(){
    fastio;

    int n; cin >> n;
    vector<string> v(n); vcin;
    sort(v.begin(), v.end(), cmp);
    string a;
    for(int i=0; i<n; i++) a+=v[i];
    if(a[0]=='0') cout << "0\n";
    else cout << a << "\n";

    return 0;
}
