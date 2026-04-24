#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main() {
    int n; cin >> n;
    vector<array<int, 2>> v;
    for(int i=0; i<n; i++){
        int k, c=0; cin >> k;
        v.push_back({k, k});
        while(1){
            if(v.size()<=1){
                break;
            }
            else if(v[v.size()-2][1]==v[v.size()-1][0]-1){
                v[v.size()-2][1]=v[v.size()-1][1];
                v.pop_back();
            }
            else if(v[v.size()-2][0]==v[v.size()-1][1]+1){
                v[v.size()-2][0]=v[v.size()-1][0];
                v.pop_back();
            }
            else{
                break;
            }
        }
        for(int j=0; j<v.size(); j++){
            //cout << v[j][0] << v[j][1] << " ";
        }
        //cout << endl;
    }
    if(v.size()==1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
