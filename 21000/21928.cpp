#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, SX, SY, EX, EY;
char C[11][11];

int op(int x, int y) {
    if (x<=0 || x>N || y<=0 || y>M) return false;
    return C[x][y]!='#';
}

bool csol(vector<array<int, 2>> v) {
    map<int, int> mp;
    int x=SX, y=SY; array<int, 2> d={1, 0};
    for (int i=0;;) {
        int a=v[i][0], b=v[i][1];
        if (mp[a+b*10+x*100+y*1000+d[0]*10000+d[1]*100000+i*1000000]++) return false;
        if (x==EX && y==EY) return true;
        if (a==1) { //goto
            i=b;
        }
        else if (a==2) { //if-open
            if (op(x+d[0], y+d[1])) i=b;
            else i=(i+1)%v.size();
        }
        else if (a==3) { //forward
            if (op(x+d[0], y+d[1])) x+=d[0], y+=d[1];
            i=(i+1)%v.size();
        }
        else if (a==4) { //left
            d={-d[1], d[0]};
            i=(i+1)%v.size();
        }
        else if (a==5) { //right
            d={d[1], -d[0]};
            i=(i+1)%v.size();
        }
    }
}

vector<array<int, 2>> vec;
int ss;

bool solve(int x) {
    if (x==0) {
        if (csol(vec)) {
            cout << vec.size() << "\n";
            for (array<int, 2> i : vec) {
                if (i[0]==1) cout << "GOTO " << i[1]+1 << "\n";
                if (i[0]==2) cout << "IF-OPEN " << i[1]+1 << "\n";
                if (i[0]==3) cout << "FORWARD\n";
                if (i[0]==4) cout << "LEFT\n";
                if (i[0]==5) cout << "RIGHT\n";
            }
            return true;
        }
        return false;
    }
    for (int j=1; j<=5; j++) {
        for (int k=0; k<=(j<=2?ss-1:0); k++) {
            vec.push_back({j, k});
            if (solve(x-1)) return true;
            vec.pop_back();
        }
    }
    return false;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> C[i][j];
        if (C[i][j]=='S') SX=i, SY=j;
        if (C[i][j]=='G') EX=i, EY=j;
    }

    for (int i=1; i<=7; i++) {
        ss=i; if (solve(i)) return 0;
    }
    assert(0);

    return 0;
}
