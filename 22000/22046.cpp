#include "dna.h"

#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int cnt[6][101010];
//ac, ct, ta, ca, tc, at

void init(string a, string b){
    a=" "+a; b=" "+b;
    for(int i=1; i<a.length(); i++){
        if(a[i]=='A' && b[i]=='C') cnt[0][i]++;
        if(a[i]=='C' && b[i]=='T') cnt[1][i]++;
        if(a[i]=='T' && b[i]=='A') cnt[2][i]++;
        if(a[i]=='C' && b[i]=='A') cnt[3][i]++;
        if(a[i]=='T' && b[i]=='C') cnt[4][i]++;
        if(a[i]=='A' && b[i]=='T') cnt[5][i]++;
    }
    for(int i=1; i<a.length(); i++)
        for(int j=0; j<6; j++) cnt[j][i]+=cnt[j][i-1];
}

int get_distance(int x, int y){
    int AC=cnt[0][y+1]-cnt[0][x];
    int CT=cnt[1][y+1]-cnt[1][x];
    int TA=cnt[2][y+1]-cnt[2][x];
    int CA=cnt[3][y+1]-cnt[3][x];
    int TC=cnt[4][y+1]-cnt[4][x];
    int AT=cnt[5][y+1]-cnt[5][x];

    int ret=0;
    int acca=min(AC, CA); AC-=acca; CA-=acca; ret+=acca;
    int cttc=min(CT, TC); CT-=cttc; TC-=cttc; ret+=cttc;
    int taat=min(TA, AT); TA-=taat; AT-=taat; ret+=taat;
    if(AC!=CT || CT!=TA) return -1; ret+=AC*2;
    if(CA!=TC || TC!=AT) return -1; ret+=CA*2;

    return ret;
}
