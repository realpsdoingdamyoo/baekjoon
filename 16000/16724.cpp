#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;

vector<string> s;
int n, m, ans=0;
vector<array<int, 2>> v;

void dfs(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m) return;
    if(s[x][y]=='X') return;
    v.push_back({x, y});
    if(s[x][y]=='x') {ans++; return;}
    char p=s[x][y];
    s[x][y]='x';
    if(p=='U') dfs(x-1, y);
    if(p=='D') dfs(x+1, y);
    if(p=='R') dfs(x, y+1);
    if(p=='L') dfs(x, y-1);
}

void redfs(int x, int y){
    while(v.size()){
        s[v[v.size()-1][0]][v[v.size()-1][1]]='X';
        v.pop_back();
    }
}

int main(){
    fastio;
    cin >> n >> m;
    s.resize(n);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dfs(i, j);
            redfs(i, j);
            /*for(int k=0; k<n; k++){
                for(int l=0; l<m; l++) cout << s[k][l];
                cout << "\n";
            }
            cout << endl;*/
        }
    }
    cout << ans;
    return 0;
}
