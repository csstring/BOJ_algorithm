//2048(easy)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second
int n,ans;
int board1[20][20];
int board2[20][20];
void ft_rot()
{
  int tmp[20][20];
  for (int i = 0; i <n; ++i){
    for (int j = 0; j< n; ++j){
      tmp[i][j] = board2[i][j];
    }
  }
  for (int i = 0; i <n; ++i){
    for (int j = 0; j< n; ++j){
      board2[i][j] = tmp[n-1-j][i];
    }
  }
}

void run(int dir)
{
  while (dir--) ft_rot();
  for (int i = 0; i <n; ++i)
  {
    int tmp[20] = {};
    int index=0;
    for (int j = 0; j <n; ++j)
    {
      if (board2[i][j] == 0) continue;
      if (tmp[index] == 0) tmp[index] = board2[i][j];
      else if (tmp[index] == board2[i][j]) tmp[index++] = 2 * board2[i][j];
      else if (tmp[index] != board2[i][j]) tmp[++index] = board2[i][j];
    }
    for (int j = 0; j <n; ++j){
      board2[i][j] = tmp[j];
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j<n; ++j){
      cin >> board1[i][j];
    }
  }
  for (int time = 0; time < (1 << 2*5); ++time)
  {
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        board2[i][j] = board1[i][j];
      }
    }
    int mod = time;
    for (int i = 0; i < 5; ++i)
    {
      int dir = mod % 4;
      mod /= 4;
      run(dir);
    }
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        ans = max(ans, board2[i][j]);
      }
    }
  }
  cout << ans;
}