#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n, arr[105], s;
vi a;

int dfs(int k, int st, int t){
    if(arr[k]==st) return 1;
    if(t>1000) return 0;
    return dfs(arr[k], st, t+1);
}

int main(){
    fastio;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i+1];
    for(int i=1; i<=n; i++) if(dfs(i, i, 0)) a.push_back(i);
    cout << a.size() << endl;
    for(int i=0; i<a.size(); i++) cout << a[i] << endl;
    return 0;
}
