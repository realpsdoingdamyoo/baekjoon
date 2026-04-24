#include <bits/stdc++.h>
using namespace std;
#define int long long

const int X=20;
int seg[1<<X+1];
void update(int p, int c){
    p+=1<<X; seg[p]=c; p>>=1;
    while(p){
        seg[p]=seg[p*2]+seg[p*2+1];
        p>>=1;
    }
}

int sum(int s, int e){
    s+=1<<X; e+=1<<X;
    int ret=0;
    for(int i=X; i>=0; i--){
    	int S=(s-1>>i)+1, E=(e+1>>i)-1;
        if(S>E) continue;
        if(S&1) ret+=seg[S];
        if(~E&1) ret+=seg[E];
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
        update(i, a);
    }

    for(int i=0; i<m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1) update(b, c);
        else cout << sum(b, c) << "\n";
    }

    return 0;
}
