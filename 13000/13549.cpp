#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vi vsd(100003);
queue<int> q;
int n, k, ans=-1, c;

void inser_t(int x){
    if(x<0 || x>100002) return;
    if(vsd[x]==0) q.push(x); vsd[x]=1;
}

void bfs(){
    if(vsd[k]==1) return;
    int sz=q.size();
    while(sz--){
        int qt=q.front();
        inser_t(qt-1); inser_t(qt+1);
        int qt1=qt-1, qt2=qt+1;
        if(qt1>0) while(qt1<100003){qt1*=2; inser_t(qt1);}
        if(qt2>0) while(qt2<100003){qt2*=2; inser_t(qt2);}

        q.pop();
    }
}

int main(){
    fastio;
    cin >> n >> k;
    vsd[n]=1; q.push(n);
    if(n>0) while(n<100003){n*=2; inser_t(n);}
    while(vsd[k]==0){
        bfs();
        c++;
    }
    cout << c;
    return 0;
}
