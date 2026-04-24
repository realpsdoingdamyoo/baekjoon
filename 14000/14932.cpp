#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll cnt[1001][1001];
ll vsd[1001][1001];
pii v[1001][1001];

int main() {
    fastio;

    ll n; cin >> n;
    forf(i, 0, n){
        forf(j, 0, n){
            S s; cin >> s;
            ll p=0;
            forf(i, 0, s.length()-1){
                p=p*10+s[i]-'0';
            }
            ll I=i, J=j;
            if(s[s.length()-1]=='U') I-=p;
            if(s[s.length()-1]=='D') I+=p;
            if(s[s.length()-1]=='L') J-=p;
            if(s[s.length()-1]=='R') J+=p;
            cnt[I][J]++;
            v[i][j]={I, J};
        }
    }
    vpii stt;
    forf(i, 0, n){
        forf(j, 0, n){
            if(cnt[i][j]==0) stt.pb({i, j});
        }
    }
    if(stt.size()>1){
        cout << "TOO SAFE";
    }
    else if(stt.size()==1){
        pii p=stt[0]; ll visit=0;
        while(!vsd[p[0]][p[1]]){
            vsd[p[0]][p[1]]=1; visit++;
            p=v[p[0]][p[1]];

        }
        if(visit==n*n){
            cout << stt[0][0]+1 << " " << stt[0][1]+1;
        }
        else cout << "TOO SAFE";
    }
    else{
        pii p={0, 0}; ll visit=0;
        while(!vsd[p[0]][p[1]]){
            vsd[p[0]][p[1]]=1; visit++;
            p=v[p[0]][p[1]];
        }
        if(visit!=n*n){
            cout << "TOO SAFE";
        }
        else cout << "THIEF LOVE IT!";
    }


	return 0;
}
