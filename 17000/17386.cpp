#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
    long long x, y;
    bool operator<=(P const &p1) {
        if(x == p1.x){
            return y <= p1.y;
        }
        return x <= p1.x;
    }
};
struct Line{
    P p1, p2;  
};
Line line[2];
int CCW(const P &p1, const P &p2, const P &p3){
    long long res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y)-(p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    if(res > 0) return 1;
    else if(res < 0) return -1;
    else return 0;
}

bool isline_intersect(Line& l1, Line &l2){
    int std1, std2;
    std1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
    std2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);
    if(std1 <= 0 && std2 <= 0){
        if(std1 == 0 && std2 == 0){
            if(l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
            if(l2.p2 <= l2.p1) swap(l2.p1, l2.p2);
            return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
        }
        else return true;
    }
    else return false;
}

void solve(){
    if(isline_intersect(line[0], line[1])){
        cout << 1;
    }
    else cout << 0;
}

void input(){
    long long x1, x2, y1, y2;
    P p1, p2;
    for(int i = 0 ; i < 2; i++){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        line[i].p1 = p1;
        line[i].p2 = p2;
    }
}

int main(){
    input();
    solve();
    return 0;
}
