#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int prev=-7;
    for(int i=0; i<n; i++){
        for(int j=0; j<v.size(); j++){
            if((v[j]!=v[v.size()-1]-1 || v[0]!=v[j]) && v[j]!=prev+1){
                prev=v[j];
                cout << v[j] << " ";
                v.erase(v.begin()+j);
                break;
            }
        }
    }
}
