#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main(){
    fastio;

    vpii v(3), ans;
    forf(i, 0, 3){cin >> v[i][0]; v[i][1]=i+1;}
    while(v[0][0]){
        ll q=v[1][0]/v[0][0];
        if(v[1][0]%v[0][0]<=v[0][0]/2){
            while(q&1==0) q>>=1;
            while(q){
                if(q&1){
                    v[1][0]-=v[0][0];
                    v[0][0]*=2;
                    ans.pb({v[1][1], v[0][1]});
                }
                else{
                    v[2][0]-=v[0][0];
                    v[0][0]*=2;
                    ans.pb({v[2][1], v[0][1]});
                }
                q>>=1;
            }
        }
        else{
            q++;
            while(q/2){
                if(q&1){
                    v[1][0]-=v[0][0];
                    v[0][0]*=2;
                    ans.pb({v[1][1], v[0][1]});
                }
                else{
                    v[2][0]-=v[0][0];
                    v[0][0]*=2;
                    ans.pb({v[2][1], v[0][1]});
                }
                q>>=1;
            }
            v[0][0]-=v[1][0];
            v[1][0]*=2;
            ans.pb({v[0][1], v[1][1]});
        }

        sortv(v);
    }
    cout << ans.size() << "\n";
    forf(i, 0, ans.size()) cout << ans[i][0] << " " << ans[i][1] << "\n";

    return 0;
}
