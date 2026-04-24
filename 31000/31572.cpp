#include <vector>
#include <bits/stdc++.h>
using namespace std;

extern int count_pair(int, int, int);
extern int find_character(int, std::vector<int>);

map<int, int> mp;
int _count_pair(int x, int y, int z) {
    if (mp[x*28572+y*380+z*555+x*y*z]) return mp[x*28572+y*380+z*555+x*y*z];
    return mp[x*28572+y*380+z*555+x*y*z]=count_pair(x, y, z);
}

int guess_palindromicity(int N) {
    vector<int> y; mp.clear();
    for (int i=1; i<N/2; i++) {
        if (_count_pair(0, i, N-i-1)==0) return 0;
        if (_count_pair(0, i, N-i-1)==1) y.push_back(i), y.push_back(N-i-1);
    }
    if (find_character(0, y)) return 0;
    if (_count_pair(0, 1, N-1)==3 && _count_pair(0, 1, N-2)==3) return 1;
    if (_count_pair(0, 1, N-1)==1 && _count_pair(0, 1, N-2)==1 && _count_pair(1, N-2, N-1)==1) return 1;
    return 0;
}
