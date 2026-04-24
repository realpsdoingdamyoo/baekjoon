#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n;
int v[15][15];
int gr[15][15], u[15][15], p[15][15];
int cu[15][15];

bool dfs(int x, int y){
    if(x==n) return true;

    for(int i=0; i<n; i++){
        if(u[x][i] || cu[y][gr[x][i]]) continue;
        u[x][i]=1; cu[y][gr[x][i]]=1;
        p[x][y]=gr[x][i];
        if(dfs(x+((y+1)/n), (y+1)%n)) return true;
        u[x][i]=0; cu[y][gr[x][i]]=0;
    }
    return false;
}

signed main(){
    fastio;

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<n; i++) for(int j=0; j<n; j++){
        if(i*n+j<(n-i-1)*n+(n-j-1))
            swap(v[i][j], v[n-i-1][n-j-1]);
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
        gr[i][j]=v[i][j]/n;

    dfs(0, 0);

    for(int i=0; i<n; i++) for(int j=0; j<n; j++){
        if(i*n+j<(n-i-1)*n+(n-j-1)){
            swap(v[i][j], v[n-i-1][n-j-1]);
            swap(p[i][j], p[n-i-1][n-j-1]);
        }
    }

    cout << 3*n-1 << "\n";
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            for(int k=j; k<n; k++){
                if(v[i][k]/n==p[i][j]){
                    swap(v[i][j], v[i][k]);
                    break;
                }
            }
        }
        cout << "D ";
        for(int j=0; j<n; j++) cout << v[i][j] << " ";
        cout << "\n";
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<n-1; i++) swap(v[i][j], v[i+1][j]);
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            for(int k=i+1; k<n; k++){
                if(v[i][j]>v[k][j]) swap(v[i][j], v[k][j]);
            }
        }

        cout << "R ";
        for(int i=0; i<n; i++) cout << v[i][j] << " ";
        cout << "\n";
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(v[i][j]>v[i][k]) swap(v[i][j], v[i][k]);
            }
        }

        cout << "D ";
        for(int j=0; j<n; j++) cout << v[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
