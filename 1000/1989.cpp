#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;
typedef long long ll;
 
ll s, temp, v;
int n,startIdx=1,endIdx=1,stemp,etemp;
// first: length of a cell, second-first: stacked length, second-second: index
stack<pair<int, pair<ll,int>>> st;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> v;
        temp = 0;
        while (!st.empty() && v < st.top().first)
        {
            temp += st.top().second.first;
            stemp=st.top().second.second;
            if(temp*st.top().first>s){
                startIdx=stemp;
                endIdx=i;
                s=temp*st.top().first;
            }
            st.pop();
        }
        temp += v;
        st.push(make_pair(v,make_pair(temp,temp>v?stemp:i+1)));
    }
    temp = 0;
    etemp=st.top().second.second;
    while (!st.empty())
    {
        temp += st.top().second.first;
        if(temp*st.top().first>s){
            startIdx=st.top().second.second;
            endIdx=etemp;
            s = temp * st.top().first;
        }
        st.pop();
    }
    cout << s << endl;
    cout<<startIdx<<' '<<endIdx<<endl;
    return 0;
}
