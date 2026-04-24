#include "sauce.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> mg(vector<int> a, vector<int> b){
    for(int i : b) a.push_back(i); return a;
}

int solve(int N){
    vector<int> V[6];
    for(int i=0; i<N; i++) V[i%6].push_back(i);
    
    int ans=0;
    for(int i=0; i<6; i++){
        ans+=6*query(V[i]);
        for(int j=i+1; j<6; j++){
            ans-=3*query(mg(V[i], V[j]));
            for(int k=j+1; k<6; k++)
                ans+=query(mg(mg(V[i], V[j]), V[k]));
        }
    }
    return ans;
}
