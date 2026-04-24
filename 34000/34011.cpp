#include <bits/stdc++.h>
using namespace std;

vector<int> p[1000100];
int d[1000100], c[1000100];

void dfs(int a){
    c[d[a]]++;
    for(int i : p[a]) d[i]=d[a]+1, dfs(i);
}

int main(){
    int n; cin >> n;
    for(int i=2; i<=n; i++){
        int a; cin >> a;
        p[a].push_back(i);
    }
    
    dfs(1);
    
    int ans=0;
    for(int i=2; i<=n; i++){
        int ret=0;
        for(int j=0; j*i<1000100; j++)
            ret+=c[i*j];
        ans=max(ans, ret);
    }
    
    cout << ans;
    
}
