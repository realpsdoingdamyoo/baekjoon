#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lf;

void solve(){
    cout << fixed;
    cout.precision(9);
    lf x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1==x2){
        cout << abs(log(y1/y2)) << "\n";
        return;
    }

    lf p=(x1*x1+y1*y1-x2*x2-y2*y2)/(2*x1-2*x2);
    lf r=sqrt((p-x1)*(p-x1)+y1*y1);
    lf t1=acos((p-x1)/r), t2=acos((p-x2)/r);

    cout << abs(log(abs(1/sin(t1)-1/tan(t1)))-log(abs(1/sin(t2)-1/tan(t2)))) << "\n";
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    ll t; cin >> t;
    while(t--) solve();

    return 0;
}
