#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

vector<array<int, 4>> u;

signed main(){
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> v;
    v=vector<vector<int>>(n, vector<int>(n-1));
    for(vector<int>& i : v) for(int& j : i) cin >> j;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(v[i][j]){
                u.push_back({i, i+2, j+1, j+1});
                if(i==n-1 || v[i+1][j]==0){
                    cout << "NO";
                    return 0;
                } v[i+1][j]=0;
            }
        }
    }

    v=vector<vector<int>>(n-1, vector<int>(n));
    for(vector<int>& i : v) for(int& j : i) cin >> j;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]){
                u.push_back({i+1, i+1, j, j+2});
                if(j==n-1 || v[i][j+1]==0){
                    cout << "NO";
                    return 0;
                } v[i][j+1]=0;
            }
        }
    }

    for(array<int, 4> i : u){
        for(array<int, 4> j : u){
            if(i[0]==i[1] ^ j[2]==j[3]) continue;
            if(i[0]==i[1]) swap(i, j);
            if(i[0]<j[0] && j[1]<i[1] && j[2]<i[2] && i[3]<j[3]){
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}
