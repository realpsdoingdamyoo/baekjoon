#include <bits/stdc++.h>
using namespace std;
typedef string S;
#define F(i, s, e) for(int i=s; i<e; i++)
#define P push_back

vector<S> A;
int n, m, a;
int bo[100][100];
S I(int n){
if(n==0) return "0";
S rs;
while(n){
rs+=(char)('0'+n%10);
n/=10;
}
reverse(rs.begin(), rs.end());
return rs;
}
void U(int x, int y){
A.P("negR "+I(x+1));
A.P("rotC "+I(y+1)+" "+I(n-1));
A.P("negR "+I(x+1));
A.P("rotC "+I(y+1)+" 1");
bo[x][y]*=-1; bo[(x+1)%n][y]*=-1; a+=4;
}
void L(int x, int y){
A.P("negC "+I(y+1));
A.P("rotR "+I(x+1)+" "+I(m-1));
A.P("negC "+I(y+1));
A.P("rotR "+I(x+1)+" 1");
bo[x][y]*=-1; bo[x][(y+1)%m]*=-1; a+=4;
}
void oneflip(int x, int y){

if(n%2==0 && m%2==0) return;
if(n%2==1){
F(i, 0, n) bo[i][y]*=-1;
A.P("negC "+I(y+1)); a++;
F(i, 0, n/2){
U((x+i*2+1)%n, y);
}
}
else if(m%2==1){
F(i, 0, m) bo[x][i]*=-1;
A.P("negR "+I(x+1)); a++;
F(i, 0, m/2){
L(x, (y+i*2+1)%m);
}
}
}

void rotR(int x, int k){int bo_[101];F(i, 0, m) bo_[i]=bo[x][i];F(i, 0, m) bo[x][(i+k+m)%m]=bo_[i];}
void rotC(int y, int k){int bo_[101];F(i, 0, n) bo_[i]=bo[i][y];F(i, 0, n) bo[(i+k+n)%n][y]=bo_[i];}

int main() {
array<int, 2> pij={0, 0};
cin >> n >> m;
F(i, 0, n) F(j, 0, m) cin >> bo[i][j];
F(i, 0, n) F(j, 0, m) if(abs(bo[pij[0]][pij[1]])>abs(bo[i][j])) pij={i, j};
if(m-pij[1]-1) {A.P("rotR "+I(pij[0]+1)+" "+I(m-pij[1]-1)); a++;}
if(n-pij[0]-1) {A.P("rotC "+I(m)+" "+I(n-pij[0]-1)); a++;}
rotR(pij[0], m-pij[1]-1);
rotC(m-1, n-pij[0]-1);
F(i, 0, n) F(j, 0, m-1) if(bo[i][j]<0) L(i, j);

F(i, 0, n-1) if(bo[i][m-1]<0) U(i, m-1);
if((m%2==1 || n%2==1) && bo[n-1][m-1]<0) oneflip(n-1, m-1);
int r=0;
F(i, 0, n) F(j, 0, m) r+=bo[i][j];
cout << r << " " << A.size() << "\n";
for(S s : A) cout << s << "\n";
return 0;
}
