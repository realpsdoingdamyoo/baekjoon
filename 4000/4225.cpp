#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<array<int, 2>> xy(100);
int n;

double width(int p, int q){
    int a=xy[p][1]-xy[q][1], b=xy[q][0]-xy[p][0];
    int c=-a*xy[p][0]-b*xy[p][1];
    int buho=0, m=0;
    for(int i=0; i<n; i++){
        int d=a*xy[i][0]+b*xy[i][1]+c;
        if(d==0) continue;
        if(d*buho<0) return 1000000.0;
        buho=d/abs(d);
        m=max(m, abs(d));
    }
    return m/sqrt(a*a+b*b);
}

int main(){
    fastio;
    int t=0;
    while(1){
        t++;
        cin >> n;
        if(n==0) break;
        for(int i=0; i<n; i++) cin >> xy[i][0] >> xy[i][1];
        double m=1000000;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                m=min(width(i, j), m);
            }
        }
        printf("Case %d: %.2f\n", t, m+0.005);
    }
    return 0;
}
