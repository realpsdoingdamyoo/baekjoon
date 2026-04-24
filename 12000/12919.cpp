#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define vcout; for(int i=0; i<n; i++) cout << v[i] << " ";
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

string s, t;

bool sht(string p){
    if(p==s) return true;
    if(p.length()<s.length()) return false;
    bool flag=false;
    if(p[p.length()-1]=='A') flag=flag||sht(p.substr(0, p.length()-1));
    if(p[0]=='B'){
        string pp=p.substr(1, p.length()-1);
        reverse(pp.begin(), pp.end());
        flag=flag||sht(pp);
    }
    return flag;
}

int main(){
    fastio;
    cin >> s >> t;
    cout << sht(t);
    return 0;
}
