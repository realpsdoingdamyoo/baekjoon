#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> pii;
typedef array<int, 3> tii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int mxend[500]={};

int main() {
    int n, cnt=0; cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mxend[32*a+b]=max(mxend[32*a+b], 32*c+d);
    }
    for(int i=0; i<500; i++){
        mxend[i]=max(mxend[i-1], mxend[i]);
        //cout << i << " " << mxend[i] << endl;
    }
    int x=32*3+1, c=0;
    while(x<=32*11+30){
        if(x==mxend[x] && x<=32*11+30){cout << "0\n"; return 0;}
        x=mxend[x];
        c++;
        //cout << x << " " << c << endl;
    }
    cout << c;
    return 0;
}
