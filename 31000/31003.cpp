#include <iostream>
#include <algorithm>
typedef int ll;
using namespace std;

ll gcd(ll a, ll b)
{
  if(b==0)  return a;
  return gcd(b, a%b);
}

ll N, arr[3001], num[3001];

int main()
{
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> arr[i];

  for(int i=0; i<N; i++)
  {
    num[i] = 0;
    for(int j=0; j<i; j++)
    {
      if(gcd(arr[i], arr[j]) != 1)  num[i]++;
    }
  }

  for(int i=0; i<N; i++)
  {
    for(int kk=i; kk<N; kk++)
    {
      if(i>0 && gcd(arr[i-1], arr[kk]) != 1)
        num[kk]--;
    }

    ll minn = 1e16, mii = i;
    for(int ci=i; ci<N; ci++)
      if(num[ci] == 0 && minn > arr[ci])
      {
        minn = arr[ci]; mii = ci;
      }
    ll tem = num[mii];
    for(int k=mii; k>i; k--)
    {
      arr[k] = arr[k-1];
      num[k] = num[k-1];
    }
    arr[i] = minn == 1e16 ? arr[i] : minn;
    num[i] = tem;
  }


  for(int i=0; i<N; i++)
    cout << arr[i] << " ";
  cout << endl;
}
