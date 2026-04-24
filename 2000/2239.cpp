#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int sdk[9][9];
vector<array<int, 2>> emt;
bool prd;

bool isok(int x, int y){
    int ch1[10]={};
    for(int i=0; i<9; i++){
        if(ch1[sdk[i][y]] && sdk[i][y]) return false;
        ch1[sdk[i][y]]++;
    }
    int ch2[10]={};
    for(int i=0; i<9; i++){
        if(ch2[sdk[x][i]] && sdk[x][i]) return false;
        ch2[sdk[x][i]]++;
    }
    int ch3[10]={};
    for(int i=0; i<9; i++){
        if(ch3[sdk[x/3*3+i/3][y/3*3+i%3]] && sdk[x/3*3+i/3][y/3*3+i%3]) return false;
        ch3[sdk[x/3*3+i/3][y/3*3+i%3]]++;
    }
    return true;
}

void bdfs(int th){
    if(prd) return;
    if(th==emt.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) cout << sdk[i][j];
            cout << endl;
        }
        prd=true;
    }
    for(int i=1; i<=9; i++){
        sdk[emt[th][0]][emt[th][1]]=i;
        if(isok(emt[th][0], emt[th][1])) bdfs(th+1);
        sdk[emt[th][0]][emt[th][1]]=0;
    }
}

int main(){
    fastio;
    for(int i=0; i<81; i++) scanf(" %1d", &sdk[i/9][i%9]);
    for(int i=0; i<81; i++) if(!sdk[i/9][i%9]) emt.push_back({i/9, i%9});
    bdfs(0);
    return 0;
}
