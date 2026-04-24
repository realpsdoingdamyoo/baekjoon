#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    map<int, int> mp;
    while(m--){
        int a, b;
        cin >> a >> b;
        mp[a]++;
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++){
        cnt+=(mp[i]==1);
    }
    cout << cnt;
}
