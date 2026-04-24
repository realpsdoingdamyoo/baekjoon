#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

class pt {
public:
    double x, y;
    double a() {
        double v = atan2(y,x);
        return v<0?v+2*PI:v;
    }
    double s() {
        return sqrt(x*x+y*y);
    }
};
int n;
vector <double> b;

int c1(pt a, pt b) {
    if (a.s() == b.s())
        return b.a()<a.a();
    else
        return b.s()<a.s();
}

int main() {
    cin >> n;
    pt a[n];
    for (int i=0; i<n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a+n, c1);
    double d = a[0].s();
    for (int i=0; i<n; i++)
        if (a[i].s() == d)
            b.push_back(a[i].a());

    double ans = 0;
    double p, q;
    n = b.size();
    for (int i=0; i<n; i++) {
        p = b[i];
        q = b[(i+1)%n];
        ans = max(ans, p-q>0?p-q:p-q+2*PI);
    }
    printf("%.9f", 180*ans/PI);
}
//////////////////////////////////
