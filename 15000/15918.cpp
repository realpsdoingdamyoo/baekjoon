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

vector<int> v, lang(24);
ll c;
int n, x, y;

void bdfs(int t){
    if(t==2*n) {c++; return;}
    if(lang[t]) {bdfs(t+1); return;}
    for(int i=0; i<v.size(); i++){
        int k=v[i];
        if(lang[t+k+1]) continue;
        v.erase(v.begin()+i);
        lang[t]=lang[t+k+1]=k;
        bdfs(t+1);
        lang[t]=lang[t+k+1]=0;
        v.insert(v.begin()+i, k);
    }
}

int main(){
    fastio;
    cin >> n >> x >> y;
    for(int i=0; i<n; i++) v.push_back(i+1);
    lang[x-1]=lang[y-1]=y-x-1;
    v.erase(v.begin()+y-x-2);
    bdfs(0);

    cout << c;

    return 0;
}
