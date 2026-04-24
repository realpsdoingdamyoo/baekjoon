#include "longesttrip.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

vector<int> longest_trip(int n, int d){
    vector<vector<int>> mr;
    mr.push_back({0});
    if(n%2==0){
        if(are_connected({0}, {1})) mr[0].push_back(1);
        else mr.push_back({1});
    }
    for(int i=2-n%2; i<n; i+=2){
        if(mr.size()==1){
            if(are_connected({i}, {i+1})){
                if(are_connected({i}, {mr[0].back()})){
                    mr[0].push_back(i); mr[0].push_back(i+1);
                }
                else if(are_connected({i+1}, {mr[0].back()})){
                    mr[0].push_back(i+1); mr[0].push_back(i);
                }
                else mr.push_back({i, i+1});
            }
            else{
                if(are_connected({i}, {mr[0].back()})){
                    mr[0].push_back(i); mr.push_back({i+1});
                }
                else{
                    mr[0].push_back(i+1); mr.push_back({i});
                }
            }
        }
        else{
            int pa=i, pb=i+1;
            if(are_connected({pa}, {pb})){
                if(!are_connected({mr[0].back()}, {pa})) swap(mr[0], mr[1]);
                if(are_connected({mr[1].back()}, {pb})){
                    mr[0].push_back(pa); mr[0].push_back(pb);
                    while(mr[1].size()){
                        mr[0].push_back(mr[1].back());
                        mr[1].pop_back();
                    } mr.pop_back();
                }
                else{
                    mr[0].push_back(pa); mr[0].push_back(pb);
                }
            }
            else{
                if(!are_connected({mr[0].back()}, {pa})) swap(pa, pb);
                if(are_connected({mr[1].back()}, {pb})){
                    mr[0].push_back(pa);
                    mr[1].push_back(pb);
                }
                else{
                    mr[0].push_back(pb);
                    mr[1].push_back(pa);
                }
            }
        }
    }

    if(mr.size()==1) return mr[0];


    if(!are_connected(mr[0], mr[1])){
        if(mr[0].size()<mr[1].size()) swap(mr[0], mr[1]);
        return mr[0];
    }

    vector<int> mr1={mr[1].front(), mr[1].back()};
    if(mr1[0]==mr1[1]) mr1.pop_back();
    if(are_connected({mr[0].front()}, mr1)){
        if(are_connected({mr[0].front()}, {mr[1].front()})){
            reverse(mr[0].begin(), mr[0].end());
            for(int i : mr[1]) mr[0].push_back(i);
            return mr[0];
        }
        else{
            reverse(mr[0].begin(), mr[0].end());
            reverse(mr[1].begin(), mr[1].end());
            for(int i : mr[1]) mr[0].push_back(i);
            return mr[0];
        }
    }
    if(are_connected({mr[0].back()}, mr1)){
        if(are_connected({mr[0].back()}, {mr[1].front()})){
            for(int i : mr[1]) mr[0].push_back(i);
            return mr[0];
        }
        else{
            reverse(mr[1].begin(), mr[1].end());
            for(int i : mr[1]) mr[0].push_back(i);
            return mr[0];
        }
    }

    int s=0, e=mr[0].size()-1, p0, p1;
    while(s<e){
        int m=s+e>>1;
        vector<int> mr0s=vector<int>(mr[0].begin()+s, mr[0].begin()+m+1);
        if(are_connected(mr0s, mr[1])) e=m; else s=m+1;
    } p0=s;

    s=0; e=mr[1].size()-1;
    while(s<e){
        int m=s+e>>1;
        vector<int> mr1s=vector<int>(mr[1].begin()+s, mr[1].begin()+m+1);
        if(are_connected({mr[0][p0]}, mr1s)) e=m; else s=m+1;
    } p1=s;

    rotate(mr[0].begin(), mr[0].begin()+p0, mr[0].end());
    reverse(mr[0].begin(), mr[0].end());
    rotate(mr[1].begin(), mr[1].begin()+p1, mr[1].end());
    for(int i : mr[1]) mr[0].push_back(i);

    return mr[0];
}
