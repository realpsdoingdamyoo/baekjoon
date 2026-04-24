#include "prison.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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


int _fill(ll x, ll y){
    if(x==0) return y/1782+1;
    else if(x<=3){
        if(x==y/1782+1) return (y%1782)/594+4;
        else{
            if(x<y/1782+1) return -1;
            else return -2;
        }
    }
    else if(x<=6){
        if(x==(y%1782)/594+4) return (y%594)/198+7;
        else{
            if(x<(y%1782)/594+4) return -1;
            else return -2;
        }
    }
    else if(x<=9){
        if(x==(y%594)/198+7) return (y%198)/66+10;
        else{
            if(x<(y%594)/198+7) return -1;
            else return -2;
        }
    }
    else if(x<=12){
        if(x==(y%198)/66+10) return (y%66)/22+13;
        else{
            if(x<(y%198)/66+10) return -1;
            else return -2;
        }
    }
    else if(x<=15){
        if(x==(y%66)/22+13){
            y=y%22;
            if(y==0) return -2;
            else if(y==21) return -1;
            else return (y-1)/10+16;
        }
        else{
            if(x<(y%66)/22+13) return -1;
            else return -2;
        }
    }
    else if(x<=17){
        if(y%22==0) return -2;
        else if(y%22==21) return -1;
        if(x==(y%22-1)/10+16){
            y=(y%22-1)%10;
            if(y==0) return -2;
            else if(y==9) return -1;
            else return (y-1)/4+18;
        }
        else{
            if(x<(y%22-1)/10+16) return -1;
            else return -2;
        }
    }
    else if(x<=19){
        if((y%22-1)%10==0) return -2;
        else if((y%22-1)%10==9) return -1;
        if(x==((y%22-1)%10-1)/4+18){
            y=((y%22-1)%10-1)%4;
            if(y==0) return -2;
            else if(y==3) return -1;
            else return 20;
        }
        else{
            if(x<((y%22-1)%10-1)/4+18) return -1;
            else return -2;
        }
    }
    else{
        if(((y%22-1)%10-1)%4>=2) return -1;
        else return -2;
    }
}

vvi devise_strategy(int n){
    vvi ans(21);
    forf(i, 0, 21) ans[i].resize(n+1);

    forf(i, 0, 21){
        if(i && i<=17) ans[i][0]=1-(i-1)/3%2;
        else ans[i][0]=(i!=20 && i);

        forf(j, 1, n+1){
            ll x=_fill(i, j-1);
            if(x<0){
                if(x==-1) ans[i][j]=ans[i][0]-2;
                else ans[i][j]=-1-ans[i][0];
            }
            else ans[i][j]=x;
        }
    }
    return ans;
}
