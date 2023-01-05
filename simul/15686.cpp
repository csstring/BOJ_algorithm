#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second
int board[53][53];
vector<pair<int,int>> CPoint;
vector<pair<int,int>> HPoint;
int pc[15];
int n,total,ans;

int cal_dis(int cx, int cy)
{
  int dis = INT32_MAX;
  for (int i = 0; i < CPoint.size(); ++i)
  {
    if (pc[i] == 1) continue;
    int hx = CPoint[i].X;
    int hy = CPoint[i].Y;
    dis = min(dis, abs(hx-cx) + abs(hy-cy));
  }
  return dis;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> total;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <n; ++j){
      cin >> board[i][j];
      if (board[i][j] == 1) HPoint.push_back({i,j});
      if (board[i][j] == 2) CPoint.push_back({i,j});
    }
  }
  ans = INT32_MAX;
  int maxchick = CPoint.size();
  fill(pc + total, pc+maxchick, 1);
  do{
    int tempmin = 0;
    for (int l = 0; l <HPoint.size(); ++l)
    {
      tempmin += cal_dis(HPoint[l].X, HPoint[l].Y);
    }
    ans = min(ans, tempmin);
  }while(next_permutation(pc, pc+maxchick));
  cout << ans;
}