#include "game.h"
using namespace std;
 
int mj1000j(int n, int k){
    if(k==0) return 1;
    int N=n/k;
    if(N&2) return 1;
    else return 0;
}
 
int anchor(int m, int k, int c){
    if(k==0) return m;
    int M=m/k;
    if(((M+1)&2)==c*2) return m+k;
    else return m-k;
}
