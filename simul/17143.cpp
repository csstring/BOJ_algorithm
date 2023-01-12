#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
#define X first
#define Y second
auto ft_comp = [](auto& a, auto& b){ return ( get<2>(a) > get<2>(b));};
vector<tuple<int,int,int>> board[100][100];
vector<tuple<int,int,int>> dumy[100][100];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,k,r,c,s,d,z,p,ans;
void move2(int i, int j)
{
  int speed, dir, size;
  tie(speed, dir, size) = board[i][j].front();
  board[i][j].pop_back();
  if (dir == 0 || dir == 1)
  {
    int tmp = speed % (2*(n-1));
    while (tmp)
    {
      i += dx[dir];
      j += dy[dir];
      if (i < 0 || j < 0|| i >=n || j >=m)
      {
        dir = 1 - dir;
        i += 2*dx[dir];
        j += 2*dy[dir];
      }
      tmp--;
    }
  }
  else
  {
    int tmp = speed % (2*(m-1));
    while (tmp)
    {
      i += dx[dir];
      j += dy[dir];
      if (i < 0 || j < 0|| i >=n || j >=m)
      {
        dir = 5 - dir;
        i += 2*dx[dir];
        j += 2*dy[dir];
      }
      tmp--;
    }
  }
  dumy[i][j].push_back({speed,dir,size});
}

void sharkMove()
{
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      if (!board[i][j].size()) continue;
      move2(i,j);
    }
  }
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      board[i][j] = dumy[i][j];
      dumy[i][j].clear();
    }
  }
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      if (board[i][j].size() <= 1) continue;
      //sort(board[i][j].begin(), board[i][j].end(), [](auto& a, auto& b){ return  get<2>(a) > get<2>(b);});
      sort(board[i][j].begin(), board[i][j].end(),
       [](auto& a , auto& b) { return get<2>(a) > get<2>(b);});
      while (board[i][j].size() > 1){
        board[i][j].pop_back();
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >>k;
  for (int i = 0; i < k; ++i){
    cin >> r >>c>>s>>d>>z;
    board[r-1][c-1].push_back({s,d-1,z});
  }
  while (p < m)
  {
    for (int i = 0; i < n;++i)
    {
      if (board[i][p].size() == 0) continue;
      ans += get<2>(board[i][p].front());
      board[i][p].pop_back();
      break;
    }
    sharkMove();
    p++;
  }
  cout << ans;
}