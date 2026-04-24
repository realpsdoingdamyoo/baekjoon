#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
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
const ll inf=2147483647, linf=140737488355327;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

pii ext(ll a, ll b, ll c){
    if(b==0) return {c, 0};

    pii eu=ext(b, a%b, c);
    eu[0]-=a/b*eu[1];
    return {eu[1], eu[0]};
}

int main(){
    fastio;

    long long A, B, C;
    cin >> A >> B >> C;

    ll a=A, b=B, c=C;

    if(a==0 && b==0){
        if(c==0) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if(a==0){
        if(c%b==0) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if(b==0){
        if(c%a==0) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if(c<a && c<b){
        cout << "NO";
        return 0;
    }

    ll d=gcd(a, b);
    if(c%d){cout << "NO"; return 0;}
    else{a/=d; b/=d; c/=d;}

    pii s=ext(a, b, c);
    if(s[0]<0){
        ll p=(-s[0])/b+1;
        s[0]+=p*b;
        s[1]-=p*a;
    }
    else{
        ll p=s[0]/b+!(s[0]%b);
        s[0]-=p*b;
        s[1]+=p*a;
    }
    if(s[1]<=0){cout << "NO"; return 0;}

    forf(i, 0, 400){
        if(s[1]-i*a<=0){cout << "NO"; return 0;}
        if(gcd(s[0]+i*b, s[1]-i*a)==1){cout << "YES"; return 0;}
    }
    cout <<"NO";

    return 0;
}
