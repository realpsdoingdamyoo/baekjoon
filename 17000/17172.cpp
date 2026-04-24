#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, sx, sy, ex, ey;
vector<array<int, 4>> v;

struct route{
    int y, x, t;

    bool operator <(const route& r) const{
        if(y!=r.y) return y<r.y;
        if(t!=r.t) return t<r.t;
        return false;
    }
};

set<route> st;

bool xfc, yfc;
int xf, yf;

void waterfall(bool& fc, int& f){
    fc=false; f=inf;

    st.insert({sy, sx, 0});

    for(array<int, 4> i : v){
        if(i[0]<sx || i[0]>ex) continue;
        if((*st.begin()).y>i[3]) continue;
        if((*prev(st.end())).y<i[1]) continue;
        route D={i[1], i[0], inf};
        route U={i[3], i[0], inf};
        set<route>::iterator S=st.lower_bound(D);
        set<route>::iterator E=prev(st.upper_bound(U));
        if(next(E)==S) continue;

        for(set<route>::iterator it=S; it!=next(E);){
            route d=*it; d.t+=abs(d.x-i[0])+abs(d.y-i[1]); d.y=i[1]; d.x=i[0];
            D=min(D, d);
            route u=*it; u.t+=abs(u.x-i[0])+abs(u.y-i[3]); u.y=i[3]; u.x=i[0];
            U=min(U, u);
            if(it==E){
                st.erase(it);
                break;
            }
            it=next(it);
            st.erase(prev(it));
        }
        st.insert(D); st.insert(U);

        if(i[0]<=ex && (*st.begin()).y<=ey && ey<=(*prev(st.end())).y) fc=true;
    }

    for(route r : st){
        f=min(f, abs(r.x-ex)+abs(r.y-ey)+r.t);
    }

    swap(sx, sy); swap(ex, ey);
    for(array<int, 4>& i : v) swap(i[0], i[1]), swap(i[2], i[3]);
    sort(v.begin(), v.end());
    st.clear();
}

signed main(){
    fastio;

    cin >> n >> sx >> sy >> ex >> ey;
    for(int i=0; i<n; i++){
        int A, B, C, D; cin >> A >> B >> C >> D;
        int a, b, c, d;
        if(sx<=ex) a=A, c=C; else a=1e8-C, c=1e8-A;
        if(sy<=ey) b=B, d=D; else b=1e8-D, d=1e8-B;
        v.push_back({a, b, c, d});
    }
    sort(v.begin(), v.end());
    if(sx>ex) sx=1e8-sx, ex=1e8-ex;
    if(sy>ey) sy=1e8-sy, ey=1e8-ey;

    waterfall(xfc, xf);
    waterfall(yfc, yf);

    if(!xfc && !yfc) cout << (ex-sx)+(ey-sy);
    else if(!xfc && yfc) cout << yf;
    else if(xfc && !yfc) cout << xf;
    else cout << min(xf, yf);

    return 0;
}
