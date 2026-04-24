#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;

vi nxt(vi v){
    for(int i=0; i<v.size()-1; i++){
        if(v[i]<v[i+1]-1){
            v[i]++;
            for(int j=0; j<i; j++) v[j]=j;
            return v;
        }
    }
    if(v[v.size()-1]==9){
        if(v.size()==10) return v;
        v.push_back(0);
        for(int j=0; j<v.size(); j++) v[j]=j;
        return v;
    }
    v[v.size()-1]++;
    for(int j=0; j<v.size()-1; j++) v[j]=j;
    return v;
}

int main(){
    fastio;
    int n; cin >> n;
    vi v(1);
    while(n--){
        vi vv=nxt(v);
        if(v==vv && n>=0){
            cout << "-1\n"; return 0;
        }
        v=vv;
    }
    for(int i=v.size()-1; i>=0; i--) cout << v[i]; cout << "\n";
    return 0;
}
