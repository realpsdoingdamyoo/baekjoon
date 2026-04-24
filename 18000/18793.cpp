#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio;cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
const int mod=1e9+7,inf=1e18;

int g,l,m,d[1010101];
int X[1010101],Y[1010101],Z[1010101],C[1010101];
int Xlen,Ylen,Zlen;
vector<int> ans[3];

int cti(char x) {
if ('0'<=x && x<='9') return x-'0';
if ('A'<=x && x<='Z') return x-'A'+10;
return x-'a'+36;
}
char itc(int x) {
if (x<=9) return '0'+x;
if (x<=35) return 'A'+x-10;
return 'a'+x-36;
}
int D(int x){return (x%g+g)%g;}

void input() {
string S;
cin >> g >> S;
//g=10;cin >> S;

l=S.length();
for (int i=0;i<l;i++) d[l-i-1]=cti(S[i]);
}

string type;

void Alg1() {
Xlen=2*m+1;Ylen=2*m;Zlen=2*m-1;

C[1]=(X[1]+Y[1]+Z[1])/g;

if (Z[1]<=d[2*m-2]-1) X[2]=D(d[2*m-1]-Y[1]);
else X[2]=D(d[2*m-1]-Y[1]-1);
Y[2]=D(d[2*m-2]-Z[1]-1);
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

for (int i=3;i<=m;i++) {
X[i]=(Z[i-1]<=d[2*m-i]-1);
Y[i]=D(d[2*m-i]-Z[i-1]-1);
Z[i]=D(d[i-1]-X[i]-Y[i]-C[i-1]);
C[i]=(X[i]+Y[i]+Z[i]+C[i-1]-d[i-1])/g;
}
X[m+1]=0;

if (C[m]==0) X[m+1]=1;
else if (C[m]==1) X[m+1]=0;
else if (C[m]==2) {
if (Z[m]==g-1) X[m+1]=1,Y[m]--,Z[m]=0;
else if (Z[m]!=g-1 && Y[m]!=0) Y[m]--,Z[m]++;
}

ans[0]=ans[1]=ans[2]={};
for (int i=0;i<Xlen;i++) ans[0].push_back(X[min(Xlen-1-i,i)+1]);
for (int i=0;i<Ylen;i++) ans[1].push_back(Y[min(Ylen-1-i,i)+1]);
for (int i=0;i<Zlen;i++) ans[2].push_back(Z[min(Zlen-1-i,i)+1]);
}

void Alg2() {
Xlen=2*m;Ylen=2*m-1;Zlen=2*m-2;

C[1]=(X[1]+Y[1]+Z[1])/g;

if (Z[1]<=d[2*m-3]-1) X[2]=D(d[2*m-2]-Y[1]);
else X[2]=D(d[2*m-2]-Y[1]-1);
Y[2]=D(d[2*m-3]-Z[1]-1);
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

for (int i=3;i<=m-1;i++) {
X[i]=(Z[i-1]<=d[2*m-i-1]-1);
Y[i]=D(d[2*m-i-1]-Z[i-1]-1);
Z[i]=D(d[i-1]-X[i]-Y[i]-C[i-1]);
C[i]=(X[i]+Y[i]+Z[i]+C[i-1]-d[i-1])/g;
}

X[m]=0;
Y[m]=D(d[m-1]-Z[m-1]-C[m-1]);
C[m]=(X[m]+Y[m]+Z[m-1]+C[m-1]-d[m-1])/g;

if (C[m]==0) {
if (Y[m]!=0) X[m]++,Y[m]--;
else if (Y[m-1]!=0) X[m]++,Y[m-1]--,Y[m]=g-2,Z[m-1]++;
else if (Z[m-1]!=0) Y[m]++,Y[m-1]++,Z[m-1]--;
else X[m-1]--,X[m]++,Y[m-1]=g-1,Y[m]=g-4,Z[m-1]=2;
}
else if (C[m]==2) {
X[m]++;Y[m-1]--;Y[m]--;Z[m-1]=0;
}

ans[0]=ans[1]=ans[2]={};
for (int i=0;i<Xlen;i++) ans[0].push_back(X[min(Xlen-1-i,i)+1]);
for (int i=0;i<Ylen;i++) ans[1].push_back(Y[min(Ylen-1-i,i)+1]);
for (int i=0;i<Zlen;i++) ans[2].push_back(Z[min(Zlen-1-i,i)+1]);
}

void Alg3() {
Xlen=2*m+1;Ylen=2*m-1;Zlen=2*m-2;X[0]=1;

C[1]=(1+Y[1]+Z[1])/g;

if (Z[1]<=d[2*m-3]-1) X[2]=D(d[2*m-2]-Y[1]);
else X[2]=D(d[2*m-2]-Y[1]-1);
Y[2]=D(d[2*m-3]-Z[1]-1);
Z[2]=D(d[1]-X[1]-Y[2]-C[1]);
C[2]=(X[1]+Y[2]+Z[2]+C[1]-d[1])/g;

for (int i=3;i<=m-1;i++) {
X[i]=(Z[i-1]<=d[2*m-i-1]-1);
Y[i]=D(d[2*m-i-1]-Z[i-1]-1);
Z[i]=D(d[i-1]-X[i-1]-Y[i]-C[i-1]);
C[i]=(X[i-1]+Y[i]+Z[i]+C[i-1]-d[i-1])/g;
}

X[m]=0;
Y[m]=D(d[m-1]-Z[m-1]-X[m-1]-C[m-1]);
C[m]=(X[m-1]+Y[m]+Z[m-1]+C[m-1]-d[m-1])/g;

if (C[m]==0) X[m]=1;
else if (C[m]==2) {
if (Y[m-1]!=0 && Z[m-1]!=g-1) Y[m-1]--,Y[m]--,Z[m-1]++;
else if (Y[m-1]!=0 && Z[m-1]==g-1) X[m]++,Y[m-1]--,Z[m-1]=0;
else if (Y[m-1]==0 && Z[m-1]!=g-1) X[m-1]--,Y[m-1]=g-1,Y[m]--,Z[m-1]++;
else if (Y[m-1]==0 && Z[m-1]==g-1) X[m-1]--,X[m]++,Y[m-1]=g-1,Z[m-1]=0;
}

ans[0]=ans[1]=ans[2]={};
for (int i=0;i<Xlen;i++) ans[0].push_back(X[min(Xlen-1-i,i)]);
for (int i=0;i<Ylen;i++) ans[1].push_back(Y[min(Ylen-1-i,i)+1]);
for (int i=0;i<Zlen;i++) ans[2].push_back(Z[min(Zlen-1-i,i)+1]);
}

void Alg4() {
Xlen=2*m;Ylen=2*m-2;Zlen=2*m-3;X[0]=1;

C[1]=(1+Y[1]+Z[1])/g;

if (Z[1]<=d[2*m-4]-1) X[2]=D(d[2*m-3]-Y[1]);
else X[2]=D(d[2*m-3]-Y[1]-1);
Y[2]=D(d[2*m-4]-Z[1]-1);
Z[2]=D(d[1]-X[1]-Y[2]-C[1]);
C[2]=(X[1]+Y[2]+Z[2]+C[1]-d[1])/g;

for (int i=3;i<=m-2;i++) {
X[i]=(Z[i-1]<=d[2*m-i-2]-1);
Y[i]=D(d[2*m-i-2]-Z[i-1]-1);
Z[i]=D(d[i-1]-X[i-1]-Y[i]-C[i-1]);
C[i]=(X[i-1]+Y[i]+Z[i]+C[i-1]-d[i-1])/g;
}

X[m-1]=(Z[m-2]<=d[m-1]-1);
Y[m-1]=D(d[m-1]-Z[m-2]-1);
Z[m-1]=D(d[m-2]-X[m-2]-Y[m-1]-C[m-2]);
C[m-1]=(X[m-2]+Y[m-1]+Z[m-1]+C[m-2]-d[m-2])/g;

if (X[m-1]+C[m-1]==0 && Y[m-1]!=g-1) {
if (Z[m-1]!=0) Y[m-1]++,Z[m-1]--;
else if (Z[m-1]==0 && Y[m-2]!=0) {
if (Y[m-1]!=1 && Z[m-2]!=g-1) X[m-1]=1,Y[m-2]--,Y[m-1]--,Z[m-2]++,Z[m-1]++;
else if (Y[m-1]!=1 && Z[m-2]==g-1) X[m-1]=2,Y[m-2]--,Y[m-1]-=2,Z[m-2]=0,Z[m-1]=3;
else if (Y[m-1]==1) X[m-1]=1,Y[m-2]--,Y[m-1]=g-1,Z[m-2]=0,Z[m-1]=3;
}
else if (Z[m-1]==0 && Y[m-2]==0) {
if (Z[m-2]!=g-1) X[m-2]--,X[m-1]=1,Y[m-2]=g-1,Y[m-1]--,Z[m-2]++,Z[m-1]=1;
else if (Z[m-2]==g-1 && Y[m-1]!=1) X[m-2]--,X[m-1]=2,Y[m-2]=g-1,Y[m-1]-=2,Z[m-2]=0,Z[m-1]=3;
else if (Z[m-2]==g-1 && Y[m-1]==1) X[m-2]--,X[m-1]=1,Y[m-2]=g-1,Y[m-1]=g-1,Z[m-2]=0,Z[m-1]=3;
}
}
else if (X[m-1]+C[m-1]==0 && Y[m-1]==g-1) {
X[m-1]=1;Y[m-2]--;Y[m-1]--;Z[m-2]++;Z[m-1]++;
}
else if (X[m-1]+C[m-1]==2 && X[m-1]==0 && C[m-1]==2) {
if (Z[m-1]!=g-1) Y[m-1]--,Z[m-1]++;
else if (Z[m-1]==g-1 && Z[m-2]!=g-1) {
if (Y[m-2]!=0) X[m-1]=1,Y[m-2]--,Y[m-1]-=2,Z[m-2]++,Z[m-1]=1;
else X[m-2]--,X[m-1]=1,Y[m-2]=g-1,Y[m-1]-=2,Z[m-2]++,Z[m-1]=1;
}
else if (Z[m-1]==g-1 && Z[m-2]==g-1) {
if (Y[m-1]!=g-1 && Y[m-1]!=g-2) {
if (Y[m-2]!=g-1) X[m-2]--,X[m-1]=g-2,Y[m-2]++,Y[m-1]+=2,Z[m-2]=g-2,Z[m-1]=g-2;
else if (Y[m-2]==g-1) X[m-1]=g-2,Y[m-2]=0,Y[m-1]+=2,Z[m-2]=g-2,Z[m-1]=g-2;
}
else {
if (Y[m-2]>=1) X[m-1]=2,Y[m-2]--,Y[m-1]-=3,Z[m-2]=0,Z[m-1]=3;
else if (Y[m-2]==0 && X[m-2]>=1) X[m-2]--,X[m-1]+=2,Y[m-2]=g-1,Y[m-1]-=3,Z[m-2]=0,Z[m-1]=3;
}
}
}
else if (X[m-1]+C[m-1]==2 && X[m-1]==1 && C[m-1]==1) {
if (Z[m-1]!=g-1 && Y[m-1]!=0) Y[m-1]--,Z[m-1]++;
else if (Z[m-1]!=g-1 && Y[m-1]==0) X[m-1]=0,Y[m-1]=g-1,Z[m-1]++;
else if (Z[m-1]==g-1 && Z[m-2]!=0) {
if (Y[m-2]!=g-1) X[m-1]=0,Y[m-2]++,Y[m-1]++,Z[m-2]--,Z[m-1]=g-2;
else if (Y[m-2]==g-1 && Y[m-1]>=2) X[m-1]=2,Y[m-2]=g-2,Y[m-1]-=2,Z[m-2]++,Z[m-1]=1;
else if (Y[m-2]==g-1 && Y[m-1]==0) Y[m-2]=g-2,Y[m-1]=g-2,Z[m-2]++,Z[m-1]=1;
else if (Y[m-2]==g-1 && Y[m-1]==1) Y[m-2]=g-2,Y[m-1]=g-1,Z[m-2]++,Z[m-1]=1;
}
else if (Z[m-1]==g-1 && Z[m-2]==0 && Y[m-2]!=0) {
if (Y[m-1]>=2) X[m-1]=2,Y[m-2]--,Y[m-1]-=2,Z[m-2]=1,Z[m-1]=1;
else if (Y[m-1]==0) Y[m-2]--,Y[m-1]=g-2,Z[m-2]=1,Z[m-1]=1;
else if (Y[m-1]==1) Y[m-2]--,Y[m-1]=g-1,Z[m-2]=1,Z[m-1]=1;
}
else if (Z[m-1]==g-1 && Z[m-2]==0 && Y[m-2]==0) {
if (Y[m-1]>=2) X[m-2]--,X[m-1]=2,Y[m-2]=g-1,Y[m-1]-=2,Z[m-2]=1,Z[m-1]=1;
else if (Y[m-1]==0) X[m-2]--,Y[m-2]=g-1,Y[m-1]=g-2,Z[m-2]=1,Z[m-1]=1;
else if (Y[m-1]==1) X[m-2]--,Y[m-2]=g-1,Y[m-1]=g-1,Z[m-2]=1,Z[m-1]=1;
}
}
else if (X[m-1]+C[m-1]==3) {
Y[m-1]--;Z[m-1]=0;
}

ans[0]=ans[1]=ans[2]={};
for (int i=0;i<Xlen;i++) ans[0].push_back(X[min(Xlen-1-i,i)]);
for (int i=0;i<Ylen;i++) ans[1].push_back(Y[min(Ylen-1-i,i)+1]);
for (int i=0;i<Zlen;i++) ans[2].push_back(Z[min(Zlen-1-i,i)+1]);
}

void type_A() {
if (type=="A1") X[1]=d[l-1],Y[1]=d[l-2]-1,Z[1]=D(d[0]-d[l-1]-d[l-2]+1);
if (type=="A2") X[1]=d[l-1],Y[1]=d[l-2]-2,Z[1]=1;
if (type=="A3") X[1]=d[l-1]-1,Y[1]=g-1,Z[1]=D(d[0]-d[l-1]+2);
if (type=="A4") X[1]=d[l-1]-1,Y[1]=g-2,Z[1]=1;
if (type=="A5") X[1]=g-1,Y[1]=d[l-3]+1,Z[1]=D(d[0]-d[l-3]);
if (type=="A6") X[1]=g-1,Y[1]=d[l-3]+2,Z[1]=g-1;

if (type=="A1" || type=="A2" || type=="A3" || type=="A4") {
if (l%2==1) m=(l-1)/2,Alg1();else m=l/2,Alg2();
}
else {
if (l%2==1) m=(l-1)/2,Alg2();else m=(l-2)/2,Alg1();
}
}
void type_B() {
if (type=="B1") X[1]=d[l-2],Y[1]=d[l-3]-1,Z[1]=D(d[0]-d[l-3]);
if (type=="B2") X[1]=d[l-2],Y[1]=d[l-3]-2,Z[1]=1;
if (type=="B3") X[1]=d[l-2]-1,Y[1]=g-2,Z[1]=1;
if (type=="B4") X[1]=d[l-2],Y[1]=1,Z[1]=g-2;
if (type=="B5") X[1]=d[l-2]-1,Y[1]=g-1,Z[1]=d[0];
if (type=="B6") X[1]=d[l-2],Y[1]=2,Z[1]=D(d[0]-3);
if (type=="B7") X[1]=d[l-2],Y[1]=1,Z[1]=1;

if (l%2==1) m=(l-1)/2,Alg3();else m=l/2,Alg4();
}

void gettype() {
if (d[l-2]>2 && D(d[0]-d[l-1]-d[l-2]+1)!=0) type="A1";
else if (d[l-2]>2 && D(d[0]-d[l-1]-d[l-2]+1)==0) type="A2";
else if (d[l-2]<=2 && d[l-1]!=1 && D(d[0]-d[l-1]+2)!=0) type="A3";
else if (d[l-2]<=2 && d[l-1]!=1 && D(d[0]-d[l-1]+2)==0) type="A4";
else if (d[l-1]==1 && d[l-2]==0 && d[l-3]<=3 && D(d[0]-d[l-3])!=0) type="A5";
else if (d[l-1]==1 && d[l-2]==0 && d[l-3]<=2 && D(d[0]-d[l-3])==0) type="A6";

else if (d[l-1]==1 && d[l-2]<=2 && d[l-3]>=4 && D(d[0]-d[l-3])!=0) type="B1";
else if (d[l-1]==1 && d[l-2]<=2 && d[l-3]>=3 && D(d[0]-d[l-3])==0) type="B2";
else if (d[l-1]==1 && (d[l-2]==1 || d[l-2]==2) && d[l-3]<=1 && d[0]==0) type="B3";
else if (d[l-1]==1 && (d[l-2]==1 || d[l-2]==2) && d[l-3]<=3 && d[0]==0) type="B4";
else if (d[l-1]==1 && (d[l-2]==1 || d[l-2]==2) && d[l-3]<=2 && d[0]!=0) type="B5";
else if (d[l-1]==1 && (d[l-2]==1 || d[l-2]==2) && d[l-3]==3 && D(d[0]-3)!=0) type="B6";
else if (d[l-1]==1 && (d[l-2]==1 || d[l-2]==2) && d[l-3]==3 && d[0]==3) type="B7";
}

void not_special() {
gettype();
if (type[0]=='A') type_A();
else type_B();
}

void sub() {
d[l/2-1]--;d[l/2]--;
for (int i=0;i<l;i++) {
if (d[i]<0) d[i]+=g,d[i+1]--;
}
if (d[l-1]==0) l--;
}

bool is_special() {
if (!(d[l/2]==0 || d[l/2-1]==0)) return false;
gettype();

return (l%2==1) ^ (type!="A5" && type!="A6");
}

void Alg5() {
int L=l,M=l/2,cn=0;

while (d[M]==0 || d[M-1]==0) sub(),cn++;
not_special();

if (Xlen==2*M) {
X[M]+=cn;ans[0][M-1]+=cn;ans[0][M]+=cn;
}
else if (Xlen==2*M-1) {
if (D(d[0]-d[l-3])!=0) type="B1",type_B();
else if (D(d[0]-d[l-3])==0) type="B2",type_B();
X[M]+=cn;ans[0][M-1]+=cn;ans[0][M]+=cn;
}
}

vector<vector<int>> small() {
int N=0;
for (int i=0,pr=1;i<l;i++) {N+=pr*d[i];pr*=g;}

if (l==1) return {{d[0]}};
else if (l==2) {
if (d[1]==1 && d[0]==0) return {{g-1},{1}};
else if (d[0]>=d[1]) return {{d[1],d[1]},{d[0]-d[1]}};
else if (d[1]>d[0]+1) return {{d[1]-1,d[1]-1},{g+d[0]-d[1]+1}};
else if (d[1]==d[0]+1 && d[0]>=1) return {{d[0],d[0]},{g-1},{1}};
}
else if (l==3) {
if (d[2]<=d[0]) return {{d[2],d[1],d[2]},{d[0]-d[2]}};
else if (d[2]>=d[0]+1 && d[1]!=0) return {{d[2],d[1]-1,d[2]},{g+d[0]-d[2]}};
else if (d[2]>=d[0]+1 && D(d[2]-d[0]-1)!=0) return {{d[2]-1,g-1,d[2]-1},{g+d[0]-d[2]+1}};
else if (d[2]>=d[0]+1 && d[1]==0) {
if (d[2]==1) return {{g-1,g-1},{1}};
else if (d[2]==2) return {{1,0,1},{g-1,g-1},{1}};
else if (d[2]>=3) return {{d[2]-2,g-1,d[2]-2},{1,1,1}};
}
}
else if (l==4) {
if (d[2]>0 || d[1]>0 || d[0]>=d[3]) {
int lef=N-d[3]*(g*g*g+1);
if (lef==2*g*g+1) {
if (d[3]==1) return {{1,1,1,1},{g-2,g-2},{3}};
else if (d[3]==g-1) return {{g-1,1,1,g-1},{g-2,g-2},{3}};
else if (d[3]!=1 && d[3]!=g-1) return {{d[3]-1,g-1,g-1,d[3]-1},{2,1,2}};
}
else if (lef<=g*g && lef>g && (lef-g)%(g+1)==0) {
int D=(lef-g)/(g+1);
if (d[3]+D==d[0]) {
if (d[3]!=1) return {{d[3]-1,g-2,g-2,d[3]-1},{1,3,1},{D,D}};
else if (d[3]==1) return {{g-1,g-1,g-1},{D+1,D+1},{1}};
}
else if (d[3]+D==g+d[0]) {
return {{d[3]-1,g-2,g-2,d[3]-1},{1,3,1},{D,D}};
}
}
else {
if (lef==0) return {{d[3],0,0,d[3]}};
else {
int D3=d[3];d[0]-=d[3];d[3]-=d[3];
for (int i=0;i<l-1;i++) {
if (d[i]<0) d[i]+=g,d[i+1]--;
}
while (l>=2 && d[l-1]==0) l--;

vector<vector<int>> get=small();
get.push_back({D3,0,0,D3});
return get;
}
}
}
else if (d[2]==0 && d[1]==0 && d[0]<=d[3]-1 && d[3]!=1) {
return {{d[3]-1,g-1,g-1,d[3]-1},{g+d[0]-d[3]},{1}};
}
else if (d[3]==1 && d[2]==0 && d[1]==0 && d[0]==0) {
return {{g-1,g-1,g-1},{1}};
}
}
else if (l==5) {
if (d[4]!=1) {
not_special();
return {ans[0],ans[1],ans[2]};
}

if (N>=(g*g*g*g + d[3]*g*g*g + d[3]*g + 1)) {
int lef=N-(g*g*g*g + d[3]*g*g*g + d[3]*g + 1);

if (lef==0) return {{1,d[3],0,d[3],1}};

if (lef==2*g*g+1) {
return {{1,d[3],1,d[3],1},{1,0,1}};
}
else if (lef<=g*g && lef>g && (lef-g)%(g+1)==0) {
int D=(lef-g)/(g+1);
if (d[3]!=0) {
if (D+1+d[3]<=g-1) return {{1,d[3]-1,1,d[3]-1,1},{g-1,D+1,g-1},{D+1}};
else if (D+1+d[3]==g+d[1]) return {{1,d[3]-1,1,d[3]-1,1},{g-1,D+1,g-1},{D+1}};
}
else if (d[3]==0) {
return {{g-1,g-1,g-1,g-1},{D+1,D+1},{1}};
}
}
else {
int D3=d[3];d[0]-=d[4];d[1]-=d[3];d[3]-=d[3];d[4]-=d[4];
for (int i=0;i<l-1;i++) {
if (d[i]<0) d[i]+=g,d[i+1]--;
}
while (l>=2 && d[l-1]==0) l--;

vector<vector<int>> get=small();
get.push_back({1,D3,0,D3,1});
return get;
}
}
else if (d[3]==0) {
return {{g-1,g-1,g-1,g-1},{1}};
}
else if (N<(g*g*g*g + d[3]*g*g*g + d[3]*g + 1) && d[3]!=0) {
int lef=N-(g*g*g*g + (d[3]-1)*g*g*g + (g-1)*g*g + (d[3]-1)*g + 1);
int D=(g+d[1]-d[3]);

if (lef==(D+1)*g+D) {
return {{1,d[3]-1,g-2,d[3]-1,1},{1,D+1,1},{D-1}};
}
else {
int D3=d[3];d[0]-=d[4];d[1]-=d[3]-1;d[2]-=g-1;d[3]-=d[3]-1;d[4]-=d[4];
for (int i=0;i<l-1;i++) {
if (d[i]<0) d[i]+=g,d[i+1]--;
}
while (l>=2 && d[l-1]==0) l--;

vector<vector<int>> get=small();
get.push_back({1,D3-1,g-1,D3-1,1});
return get;
}
}
}
else if (l==6) {
if (d[5]!=1) {
if (d[4]>=3 && D(d[0]-d[5]-d[4]+1)!=0) X[1]=d[5],Y[1]=d[4]-1,Z[1]=D(d[0]-d[5]-d[4]+1);
else if (d[4]>=3 && D(d[0]-d[5]-d[4]+1)==0) X[1]=d[5],Y[1]=d[4]-2,Z[1]=1;
else if (d[4]<=2 && d[5]!=1 && D(d[0]-d[5]+2)!=0) X[1]=d[5]-1,Y[1]=g-1,Z[1]=D(d[0]-d[5]+2);
else if (d[4]<=2 && d[5]!=1 && D(d[0]-d[5]+2)==0) X[1]=d[5]-1,Y[1]=g-2,Z[1]=1;

C[1]=(X[1]+Y[1]+Z[1])/g;

m=3;
if (Z[1]<=d[2*m-3]-1) X[2]=D(d[2*m-2]-Y[1]);
else X[2]=D(d[2*m-2]-Y[1]-1);
Y[2]=D(d[2*m-3]-Z[1]-1);
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

X[3]=0;
Y[3]=D(d[2]-Z[2]-C[2]);
C[3]=(X[3]+Y[3]+Z[2]+C[2]-d[2])/g;

if (C[3]==0) {
if (Y[3]!=0) X[3]++,Y[3]--;
else if (Y[2]!=0) X[3]++,Y[2]--,Y[3]=g-2,Z[2]++;
else if (Z[2]!=0) Y[3]++,Y[2]++,Z[2]--;
else {
if (X[2]!=0) X[2]--,X[3]=g-1,Y[2]=1,Y[3]=1;
else if (X[2]==0) {
if (X[1]==1) return {{2,0,0,0,0,2},{1,1},{g-4}};
else if (X[1]!=1 && Y[1]!=g-1) X[1]--,X[2]=g-1,Y[1]++,Y[3]=g-2,Z[2]=1;
else if (X[1]!=g-1 && Z[1]==g-1 && Y[1]==g-1) return {{X[1]+1,0,0,0,0,X[1]+1},{1,1},{g-4}};
}
}
}
else if (C[3]==2) {
X[3]++;Y[2]--;Y[3]--;Z[2]=0;
}

return {{X[1],X[2],X[3],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[2],Z[1]}};
}
else if (d[5]==1) {
if (D(d[0]-d[4]+1)!=0 && D(d[0]-d[4]+2)!=0) {
Z[1]=D(d[0]-d[4]+1);
if (g+d[4]-1<=g-1) X[1]=1,Y[1]=g+d[4]-2;
else X[1]=g-1,Y[1]=d[4];
C[1]=(X[1]+Y[1]+Z[1]-d[0])/g;

if (g+d[3]-1<=g-1) X[2]=1,Y[2]=g+d[3]-2;
else X[2]=g-1,Y[2]=d[3];
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

int s=g+d[2]-C[2]-Z[1];
if (s<=g-1) X[3]=0,Y[3]=s;
else X[3]=g-1,Y[3]=s-g+1;

return {{X[1],X[2],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[1]}};
}
else if (D(d[0]-d[4]+2)==0 && d[2]!=0) {
if (g+d[4]-1<=g-1) X[1]=1,Y[1]=g+d[4]-2;
else X[1]=g-1,Y[1]=d[4];
Z[1]=g-1;
C[1]=(X[1]+Y[1]+Z[1]-d[0])/g;

if (g+d[3]-1<=g-1) X[2]=1,Y[2]=g+d[3]-2;
else X[2]=g-1,Y[2]=d[3];
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

int s=g+d[2]-C[2]-Z[1];
if (s<=g-1) X[3]=0,Y[3]=s;
else X[3]=g-1,Y[3]=s-g+1;

return {{X[1],X[2],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[1]}};
}
else if (D(d[0]-d[4]+2)==0 && d[2]==0) {
if (d[4]==0) {
X[1]=g-2;Y[1]=1;
Z[1]=g-1;
C[1]=(X[1]+Y[1]+Z[1]-d[0])/g;

X[2]=0;Y[2]=d[3];
Z[2]=D(d[1]-X[2]-Y[2]-1);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

int s=g-C[2]-Z[2];
if (s<=g-1) X[3]=0,Y[3]=s;
else X[3]=g-1,Y[3]=s-g+1;

return {{X[1],X[2],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[2],Z[1]}};
}
else if (d[4]==1 && d[0]==g-1) {
X[1]=g-1;Y[1]=1;
Z[1]=g-1;
C[1]=(X[1]+Y[1]+Z[1]-d[0])/g;

X[2]=0;Y[2]=d[3];
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

int s=g-C[2]-Z[2];
if (s<=g-1) X[3]=0,Y[3]=s;
else X[3]=g-1,Y[3]=s-g+1;

return {{X[1],X[2],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[2],Z[1]}};
}
else if (d[4]==2 && d[0]==0) {
X[1]=g-1;Y[1]=2;
Z[1]=g-1;
C[1]=(X[1]+Y[1]+Z[1]-d[0])/g;

X[2]=0;Y[2]=d[3];
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);
C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

if (C[2]!=2) {
int s=g-C[2]-Z[2];
if (s<=g-1) X[3]=0,Y[3]=s;
else X[3]=g-1,Y[3]=s-g+1;
}
else if (C[2]==2) {
return {{1,2,g-2,g-2,2,1},{1,g-3,1},{g-2}};
}
else if (d[4]>=3) {
C[4]=(D(d[3]-1)+1-d[3])/g;
C[1]=1;int z=D(d[1]-d[3]-1+C[4]);
C[2]=(2-C[4]+D(d[3]-1)+z-d[1])/g;
}

return {{X[1],X[2],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[2],Z[1]}};
}
else if (d[4]>=3) {
C[4]=(D(d[3]-1)+1-d[3])/g;
C[1]=1;int z=D(d[1]-d[3]-1+C[4]);
C[2]=(2-C[4]+D(d[3]-1)+z-d[1])/g;
return {{1,1-C[4],0,0,1-C[4],1},
{d[4]-1,D(d[3]-1),2-C[2],D(d[3]-1),d[4]-1},{g-2,z,g-2}};
}
}
else if (D(d[0]-d[4]+1)==0 && d[3]!=0) {
if (d[4]!=g-1) {
X[1]=g-1;Y[1]=d[4]+1;Z[1]=g-1;
C[1]=(X[1]+Y[1]+Z[1]-d[0])/g;
X[2]=0;Y[2]=d[3]-1;
Z[2]=D(d[1]-X[2]-Y[2]-C[1]);

C[2]=(X[2]+Y[2]+Z[2]+C[1]-d[1])/g;

int s=g+d[2]-C[2]-Z[1];
if (s<=g-1) X[3]=0,Y[3]=s;
else X[3]=g-1,Y[3]=s-g+1;

return {{X[1],X[2],X[3],X[2],X[1]},{Y[1],Y[2],Y[3],Y[2],Y[1]},{Z[1],Z[2],Z[1]}};
}
else if (d[4]==g-1) {
int y=1,x;
while (D(d[1]-3-y)>=g-2) y++;
x=D(d[3]-y);

C[1]=(3+y+D(d[1]-3-y)-d[1])/g;

int mu=0;C[2]=(x+D(d[2]-x-1-C[1]+mu)+C[1]+1-d[2])/g;
if (C[2]>1) mu=1,C[2]=1;
C[3]=(x+(y-C[2])+C[2]-d[3])/g;

return {{1,3-C[3],x-mu,x-mu,3-C[3],1},
{g-4,y-C[2]+mu,D(d[2]-x-1-C[1]+mu),y-C[2]+mu,g-4},
{1,D(d[1]-3-y)+(C[2]-mu)+C[3],1}};
}
}
else if (D(d[0]-d[4]+1)==0 && d[3]==0) {
if (d[4]==0) {
if (d[2]!=0 || (d[2]==0 && d[1]!=0 && d[1]!=g-1)) {
d[0]-=1;d[5]-=1;

for (int i=0;i<l-1;i++) {
    if (d[i]<0) d[i]+=g,d[i+1]--;
}
while (l>=2 && d[l-1]==0) l--;

vector<vector<int>> get=small();
get.push_back({1,0,0,0,0,1});
return get;
}
else if (d[2]==0 && d[1]==0) {
return {{1,0,0,0,0,1},{g-2}};
}
else if (d[2]==0 && d[1]==g-1) {
return {{g-1,0,1,0,g-1},{g-1,g-2,g-2,g-1},{1,0,1}};
}
}
else if (d[4]==1) {
if (d[2]>=2 || (d[2]==1 && d[1]!=0 && d[1]!=1)) {
d[0]-=1;d[1]-=1;d[4]-=1;d[5]-=1;

for (int i=0;i<l-1;i++) {
    if (d[i]<0) d[i]+=g,d[i+1]--;
}
while (l>=2 && d[l-1]==0) l--;

vector<vector<int>> get=small();
get.push_back({1,1,0,0,1,1});
return get;
}
else if (d[2]==1 && d[1]==0) {
return {{1,0,g-1,g-1,0,1},{1,g-1,1},{g-2}};
}
else if (d[2]==1 && d[1]==1) {
return {{1,1,0,0,1,1},{g-1,g-1}};
}
else if (d[2]==0 && d[1]>=2) {
if (d[1]==2) return {{1,1,0,0,1,1},{g-d[1]+1}};
else return {{1,1,0,0,1,1},{d[1]-2,d[1]-2},{g-d[1]+1}};
}
else if (d[2]==0 && d[1]==1) {
return {{1,0,0,0,0,1},{1,0,0,0,1},{g-2}};
}
else if (d[2]==0 && d[1]==0) {
return {{1,0,0,0,0,1},{g-1,g-1,g-1,g-1}};
}
}
else if (d[4]==2) {
if (d[2]>=2 || (d[2]==1 && d[1]!=0 && d[1]!=1)) {
d[0]-=1;d[1]-=2;d[4]-=2;d[5]-=1;

for (int i=0;i<l-1;i++) {
    if (d[i]<0) d[i]+=g,d[i+1]--;
}
while (l>=2 && d[l-1]==0) l--;

vector<vector<int>> get=small();
get.push_back({1,2,0,0,2,1});
return get;
}
else if (d[2]==1 && d[1]==0) {
return {{1,1,g-1,g-1,1,1},{1,g-2,1},{g-1}};
}
else if (d[2]==1 && d[1]==1) {
return {{1,1,g-1,g-1,1,1},{1,g-1,1},{g-1}};
}
else if (d[2]==0 && d[1]>=3) {
if (d[1]==3) return {{1,2,0,0,2,1},{g-1},{1}};
else return {{1,2,0,0,2,1},{d[1]-3,d[1]-3},{g-d[1]+3}};
}
else if (d[2]==0 && d[1]==2) {
return {{1,1,g-1,g-1,1,1},{1,0,1},{g-1}};
}
else if (d[2]==0 && d[1]==1) {
return {{1,0,0,0,0,1},{2,0,0,0,2},{g-2}};
}
else if (d[2]==0 && d[1]==0) {
return {{1,1,g-1,g-1,1,1},{g-2,g-2},{2}};
}
}
else if (d[4]==3) {
int y=1;
while (D(d[1]-1-y)==0 || D(d[1]-1-y)==g-1) y++;
C[1]=(2+y+D(d[1]-1-y)-d[1])/g;
C[2]=(g-y-1+D(d[2]+y+2)+g-1-d[2])/g;

return {{1,0,g-y-1-C[1],g-y-1-C[1],0,1},
{2,y-C[2]+1+C[1],D(d[2]+y+2),y-C[2]+1+C[1],2},
{g-1,D(d[1]-1-y)+(C[2]-1)-C[1],g-1}};
}
else if (d[4]>=4) {
int y=1;
while (D(d[1]-1-y)==0 || D(d[1]-1-y)==g-1) y++;
C[1]=(1+y+D(d[1]-1-y)-d[1])/g;
C[2]=(g-y+1+D(d[2]+y-1)-d[2])/g;

return {{1,2,g-y-C[1],g-y-C[1],2,1},
{d[4]-3,y-C[2]+C[1],D(d[2]+y-1),y-C[2]+C[1],d[4]-3},
{1,D(d[1]-2-y)+C[2]-C[1],1}};
}
}
}
}

return {{0}};
}

void small_case() {
vector<vector<int>> ret=small();
while (ret.size()<3) ret.push_back({0});
ans[0]=ret[0];ans[1]=ret[1];ans[2]=ret[2];
}

void solve() {
input();
if (l<7) small_case();
else if (is_special()) Alg5();
else not_special();

for (int j : {0,1,2}) {
for (int i=(int)ans[j].size()-1;i>=0;i--) cout << itc(ans[j][i]);cout << " ";
}
cout << "\n";
}

signed main() {
fastio;

int T;cin >> T;
while (T--) solve();

return 0;
}
