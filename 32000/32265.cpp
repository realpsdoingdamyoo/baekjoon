#include "message.h"
#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

void send_message(vector<bool> M, vector<bool> C){
    int k=M.size();
    for(int i=k; i<1025; i++) M.push_back(!M[k-1]);

    vector<vector<bool>> pc(66, vector<bool>(31, false));

    int c=0;
    for(int i=0; i<31; i++){
        if(C[i]) continue;
        int j=0;
        while(C[(i+j+1)%31]) j++;
        pc[j][i]=true;
        for(int k=j+1; k<66; k++) pc[k][i]=M[c++];
    }
    for(vector<bool> p : pc) send_packet(p);
}

vector<bool> receive_message(vector<vector<bool>> R){
    vector<int> nxt(31);
    for(int i=0; i<31; i++){
        nxt[i]=(i+1)%31;
        for(int j=0; j<16; j++){
            if(R[j][i]) break;
            nxt[i]=(nxt[i]+1)%31;
        }
    }
    vector<bool> ret;

    for(int i=0; i<31; i++){
        int x=i, cyc=10101;
        for(int j=1; j<=16; j++){
            x=nxt[x];
            if(x==i) cyc=min(cyc, j);
        }
        if(cyc!=16) continue;

        int k=0;
        while(k<66 && !R[k][i]) k++; k++;

        for(int j=k; j<66; j++) ret.push_back(R[j][i]);
    }

    bool lst=ret.back();
    while(ret.size() && ret.back()==lst) ret.pop_back();
    return ret;
}
