#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int c, x[6]; cin >> c;
    for(int i=0; i<6; i++) cin >> x[i];
    
    if(c==1){
        for(int i=0; i<6; i++){
            int r=0;
            for(int j=0; j<6; j++){
                if(((x[(i+j)%6]-1)&(1<<j))==0) r+=1<<j;
            }
            cout << r+1 << " ";
        }
    }
    else{
        int r[6]={};
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                if(((x[i]-1)&(1<<j))==0) r[(i+j)%6]+=1<<j;
            }
        }
        
        for(int i=0; i<6; i++) cout << r[i]+1 << " ";
    }

    return 0;
}
