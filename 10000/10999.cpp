#include <bits/stdc++.h>
using namespace std;
#define int long long

const int X=20;
int seg[1<<X+1], lazy[1<<X+1];

void prop(int p){
    lazy[p*2]+=lazy[p]/2; lazy[p*2+1]+=lazy[p]/2;
    seg[p]+=lazy[p]; lazy[p]=0;
}
void segup(int p){
    seg[p]=seg[p*2]+lazy[p*2]+seg[p*2+1]+lazy[p*2+1];
}

void update(int s, int e, int x){
    int S=s+=1<<X, E=e+=1<<X;
    while(s<=e){
        if(s&1) lazy[s]+=x;
        if(~e&1) lazy[e]+=x;
        s=s+1>>1; e=e-1>>1; x*=2;
    }
    for(int i=1; i<=X; i++) segup(S>>i), segup(E>>i);
}

int sum(int s, int e){
    s+=1<<X; e+=1<<X;
    for(int i=X; i>=1; i--) prop(s>>i), prop(e>>i);
    int ret=0;
    while(s<=e){
        if(s&1) ret+=seg[s]+lazy[s];
        if(~e&1) ret+=seg[e]+lazy[e];
        s=s+1>>1; e=e-1>>1;
    }
    return ret;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        int a; cin >> a;
        update(i, i, a);
    }

    for(int i=0; i<m+k; i++){
        int a; cin >> a;
        if(a==1){
            int b, c, d;
            cin >> b >> c >> d;
            update(b, c, d);
        }
        else{
            int b, c;
            cin >> b >> c;
            cout << sum(b, c) << "\n";
        }
    }

    return 0;
}
