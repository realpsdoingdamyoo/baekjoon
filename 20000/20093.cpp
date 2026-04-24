#include "coins.h"
#define V std::vector<int>
int r,z;V coin_flips(V b, int c){r=c;z=0;for(int j:b)r^=j*z++;return {r};}int find_coin(V b){r=z=0;for(int j:b)r^=j*z++;return r;}
