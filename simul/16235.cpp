//나무재테크
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#define DEBUG 0
using namespace std;
#define X first
#define Y second
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int n,m,k,ans;
queue<pair<int,int>> diePoint;
deque<pair<int,int>> treePoint;
queue<pair<int,int>> fallTree;
deque<int> tree[10][10];
queue<int> die[10][10];
int feed[10][10];
int board[10][10];
void spring()
{
  deque<pair<int,int>>::iterator pit = treePoint.begin();
  deque<int>::iterator tit;
  while (pit != treePoint.end())
  {
    int x = pit->X;
    int y = pit->Y;
    tit = tree[x][y].begin();
    while (tit != tree[x][y].end())
    {
      if (board[x][y] >= *tit)
      {
        board[x][y] -= *tit;
        (*tit)++;
        if (*tit % 5 == 0) fallTree.push({x,y});
        tit++;
      }
      else
      {
        diePoint.push({x,y});
        die[x][y].push(*tit);
        tit = tree[x][y].erase(tit);
      }
    }
    if (tree[x][y].empty()) pit = treePoint.erase(pit);
    else pit++;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i <n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> feed[i][j];
  for (int i = 0; i <m; ++i){
    int x,y,age;
    cin >> x >> y >> age;
    tree[x-1][y-1].push_back(age);
    treePoint.push_back({x-1,y-1});
  }
  for (int i = 0 ; i < n; ++i)
    fill(board[i], board[i] + n, 5);
  int time = 0;
  while (time != k)
  {
    time++;
    spring();
    //summer
    while (!diePoint.empty())
    {
      pair<int,int> cur = diePoint.front(); diePoint.pop();
      int val = die[cur.X][cur.Y].front() / 2; 
      die[cur.X][cur.Y].pop();
      board[cur.X][cur.Y] += val;
    }
    //fall
    while (!fallTree.empty())
    {
      pair<int,int> cur = fallTree.front(); fallTree.pop();
      for (int dir = 0; dir <8; ++dir)
      {
        int nx = cur.X +dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny <0 || nx >=n || ny >= n) continue;
        if (tree[nx][ny].size() == 0) treePoint.push_back({nx,ny});
        tree[nx][ny].push_front(1);
      }
    }
    //winter
    for (int i = 0; i <n; ++i)
      for (int j = 0; j < n; ++j)
        board[i][j] += feed[i][j];
  }
  while (!treePoint.empty())
  {
    pair<int,int> cur = treePoint.front(); treePoint.pop_front();
    ans += tree[cur.X][cur.Y].size();
  }
  cout << ans;
}