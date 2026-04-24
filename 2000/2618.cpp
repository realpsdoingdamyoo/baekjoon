#include <iostream>
#include <algorithm>
using namespace std;

struct loc
{
  int x;
  int y;
};

loc wee[1005];
loc A, B;
int N, W, answer;
int cas[1005];

int dp[1005][1005];


int minn(int a, int b) { return a < b ? a : b ; }
int abss(int a)  { return a < 0 ? -a : a ; }
int dist(loc a, loc b)
{
  return abss(a.x - b.x) + abss(a.y - b.y);
}

int path(int tar, int po1, int po2)
{
  if(tar >= W+2)  return 0;
  if (dp[po1][po2] != -1) return dp[po1][po2];

  loc X = wee[tar];
  loc c1 = wee[po1];
  loc c2 = wee[po2];
  int dic1 = dist(c1, X);
  int dic2 = dist(c2, X);

  int cho1 = path(tar + 1, tar, po2) + dic1;
  int cho2 = path(tar + 1, po1, tar) + dic2;

  if(cho1 < cho2)
  {
    if(cas[tar] == -1)  cas[tar] = 1;
    return dp[po1][po2] = cho1;
  }
  else
  {
    if(cas[tar] == -1)  cas[tar] = 2;
    return dp[po1][po2] = cho2;
  }
}

void fidpo(int p1, int p2, int k)
{
  if(k>=W+2)  return;
  if(dp[p1][k]+dist(wee[p2], wee[k]) < dp[k][p2]+dist(wee[p1], wee[k]))
  {
    cas[k] = 2;
    fidpo(p1, k, k+1);
  }
  else
  {
    cas[k] = 1;
    fidpo(k, p2, k+1);
  }
}


int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  cin >> W;

  for(int i=2; i<=W+1; i++)
    cin >> wee[i].x >> wee[i].y;

  for(int i=0; i<1005; i++)
    for(int j=0; j<1005; j++)
      dp[i][j] = -1;

  for(int i=0; i<1005; i++)
    cas[i] = -1;

  wee[0].x = 1;  wee[0].y = 1;  wee[1].x = N;  wee[1].y = N;
  answer = path(2, 0, 1);

  fidpo(0,1,2);
  cout << answer << '\n';
  for(int i=2; i<=W+1; i++)
    cout << cas[i] << '\n';
  return 0;
}
