#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll a=0, b, c=4;

    while(c--){cin >> b; a+=b;}

    a-=2;

    cout << (a)%4+1;

    

    return 0;

 }
