#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e7;

int n, l;
string s[55];
map<string, int> mm;

string out(string p) {
    int s=0, e=p.length()-1;
    while (s<e && p[s]!='.' && p[e]!='.') s++, e--;
    return p.substr(s, e-s+1);
}

int dp(string p) {
    string P=p;
    if (p.length()==1 && p[0]!='.') return 1;
    if (p.length()==0) return 1;
    if (mm.find(p)!=mm.end()) return mm[p];

    int ret=0;
    if (p[0]=='.') {
        for (int i=1; i<=n; i++) {
            if (s[i].length()>p.length()) continue;
            if (p[s[i].length()-1]!='.') continue;

            int cu=1;
            for (int j=0; j<s[i].length(); j++) {
                p[j]=s[i][j];
                if (p[j]!=p[p.length()-1-j] && p[p.length()-1-j]!='.') cu=0;
            }
            if (cu) ret+=dp(out(p));
            for (int j=0; j<s[i].length(); j++) p[j]='.';
        }
    }
    else {
        for (int i=1; i<=n; i++) {
            if (s[i].length()>p.length()) continue;
            if (p[p.length()-s[i].length()]!='.') continue;

            int cu=1;
            for (int j=0; j<s[i].length(); j++) {
                p[p.length()-s[i].length()+j]=s[i][j];
                if (p[p.length()-s[i].length()+j]!=p[s[i].length()-j-1] && p[s[i].length()-j-1]!='.') cu=0;
            }
            if (cu) ret+=dp(out(p));
            for (int j=0; j<s[i].length(); j++) p[p.length()-s[i].length()+j]='.';
        }
    }

    return mm[p]=ret;
}

signed main() {
    fastio;

    cin >> n >> l;
    for (int i=1; i<=n; i++) cin >> s[i];
    string p(l, '.');
    cout << dp(p);


    return 0;
}
