#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n, r;
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
    while(s<=e){
        if(s&1) ret+=seg[s];
        if(~e&1) ret+=seg[e];
        s=s+1>>1; e=e-1>>1;
    }
    return ret;
}

signed main(){
    fastio;
    
    cin>>n;
    while(n--){
        int x; cin >>x;
        update(x, 1);
        r+=sum(x+1, 1<<19);
    }
    if(r%2==0) cout << "Yes"; else cout << "No";
    
    
    return 0;
}
