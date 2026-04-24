#include <bits/stdc++.h>
using namespace std;

bool cmp1(array<int, 3> a, array<int, 3> b) {
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0] && a[1] < b[1])
        return true;
    else
        return false;
}
bool cmp2(array<int, 3> a, array<int, 3> b) {
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1] && a[0] < b[0])
        return true;
    else
        return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> lnkx(n+1), lnky(n+1);
        vector<array<int, 3>> v(n);
        vector<array<int, 6>> xl, yl;
        int c = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i][0] >> v[i][1]; v[i][2]=i;
        }

        sort(v.begin(), v.end(), cmp1);

        for (int i = 0; i < n; i += 2) {
            if (v[i][0] == v[i + 1][0]) {
                xl.push_back({v[i][0], v[i][1], v[i][2], v[i + 1][0], v[i + 1][1], v[i + 1][2]});
            } else {
                if (c == 0) {
                    cout << "NO\n";
                }
                c++;
            }
        }
        sort(v.begin(), v.end(), cmp2);

        for (int i = 0; i < n; i += 2) {
            if (v[i][1] == v[i + 1][1]) {
                yl.push_back({v[i][0], v[i][1], v[i][2], v[i + 1][0], v[i + 1][1], v[i + 1][2]});
            } else {
                if (c == 0) {
                    cout << "NO\n";
                }
                c++;
            }
        }

        for (int i = 0; i < xl.size(); i++) {
            //cout << xl[i][0] << " " << xl[i][1] << " " << xl[i][3] << " " << xl[i][4] << endl;
            lnkx[xl[i][2]]=xl[i][5];
            lnkx[xl[i][5]]=xl[i][2];
        }
        for (int i = 0; i < yl.size(); i++) {
            //cout << yl[i][0] << " " << yl[i][1] << " " << yl[i][3] << " " << yl[i][4] << endl;
            lnky[yl[i][2]]=yl[i][5];
            lnky[yl[i][5]]=yl[i][2];
        }

        for (int i = 0; i < xl.size(); i++) {
            for (int j = 0; j < yl.size(); j++) {
                if ((xl[i][0] - yl[j][0]) * (xl[i][0] - yl[j][3]) < 0 && (yl[j][1] - xl[i][1]) * (yl[j][1] - xl[i][4]) < 0) {
                    /*cout << xl[i][0] << " " << xl[i][1] << " " << xl[i][3] << " " << xl[i][4] << " ";
                    cout << yl[j][0] << " " << yl[j][1] << " " << yl[j][3] << " " << yl[j][4] << endl;*/
                    if (c == 0) {
                        cout << "NO\n";
                    }
                    c++;
                }
            }
        }

        int pc=0;
        int i=lnkx[0];
        while(i!=0){
            if(pc%2) i=lnkx[i];
            else i=lnky[i];
            pc++;
        }
        if(pc<n-1){
            if (c == 0) {
                cout << "NO\n";
            }
            c++;
        }

        if (c == 0) {
            cout << "YES\n";
        }
    }

    return 0;
}
