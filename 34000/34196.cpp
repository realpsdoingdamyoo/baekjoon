#include <bits/stdc++.h>
using namespace std;

string Solve[6], Try[6];

signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    Solve[1]="1111011111111";
    Solve[2]="1111011111111";
    Solve[3]="1111010111111";
    Solve[4]="1111010111111";
    Solve[5]="1111010111111";
    Try[1]="0002102003210";
    Try[2]="0100804320233";
    Try[3]="0001102300110";
    Try[4]="0003000010110";
    Try[5]="0110000640101";

    int Q; cin >> Q;
    while (Q--) {
        int a; char c; cin >> a >> c;
        cout << (Solve[a][c-'A']=='1'?"Yes ":"No ") << Try[a][c-'A'] << "\n";
    }

    return 0;
}
