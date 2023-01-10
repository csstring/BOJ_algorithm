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
int n,H,m,x,y,ans;
int board[30][10];
vector<pair<int,int>> C;
bool goDown()
{
  int line;
  for (int k = 0; k <m; ++k)
  {
    line = k;
    for (int i =0; i <n; ++i)
    {
      if (board[i][line] == -1) continue;
      line = board[i][line];
    }
    if (line != k) return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> H >> n;
  for (int i = 0; i <30; ++i)
    fill(board[i], board[i] + 10, -1);
  for (int i = 0; i < H; ++i){
    cin >> x >>y;
    board[x-1][y-1] = y;
    board[x-1][y] = y -1;
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m-1; ++j){
      if (board[i][j] != -1 || board[i][j+1] != -1) continue;
      C.push_back({i,j}); 
    }
  }
  vector<int> np(C.size(),0);
  if (goDown()){
    cout << 0; return(0);
  }
  for (int l = 1; l < 4; ++l)
  {
    if (np.size() < l) break;
    np[np.size() - l] = 1;
    do {
      queue<pair<int,int>> temp;
      bool flag = true;
      for (int i =0; i < np.size(); ++i)
      {
        if (np[i] == 0) continue;
        pair<int,int> cur = C[i];
        if (board[cur.X][cur.Y] != -1 || board[cur.X][cur.Y+1] != -1) {
          flag = false;
          break;
        }
        temp.push({cur.X,cur.Y});
        board[cur.X][cur.Y] = cur.Y + 1;
        board[cur.X][cur.Y + 1] = cur.Y;
      }
      if (flag && goDown()){
        cout << l;
        return(0);
      } 
      while (!temp.empty()){
        pair<int,int> cur = temp.front(); temp.pop();
        board[cur.X][cur.Y] = -1;
        board[cur.X][cur.Y + 1] = -1;
      }
    }while (next_permutation(np.begin(), np.end()));
  }
  cout << -1;
}