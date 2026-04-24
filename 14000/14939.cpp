#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
#define vcout; for(int i=0; i<v.size(); i++) cout << v[i] << " ";
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vector<vi> v(10);
vector<vi> u(10);

void click(int x, int y){
    u[x][y]^=1;
    if(x>0) u[x-1][y]^=1;
    if(y>0) u[x][y-1]^=1;
    if(x<9) u[x+1][y]^=1;
    if(y<9) u[x][y+1]^=1;
}

int bf(int bit){
    u=v;
    int s=0;

    for(int i=0; i<10; i++){
        if((bit&(1<<i))){
            s++;
            click(0, i);
        }
    }

    for(int i=1; i<10; i++){
        for(int j=0; j<10; j++){
            if(u[i-1][j]==1){
                s++;
                click(i, j);
            }
        }
    }
    int k=0; for(int i=0; i<10; i++) k+=u[9][i];
    return k?10000000:s;
}

int main(){
    fastio;

    for(int i=0; i<10; i++){
        string s; cin >> s;
        for(int j=0; j<10; j++) v[i].push_back(s[j]=='O');
    }
    int mn=10000000;
    for(int i=0; i<1024; i++) mn=min(mn, bf(i));
    cout << (mn==10000000?-1:mn);
    return 0;
}
