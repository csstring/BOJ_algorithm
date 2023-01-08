//뱀
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 0,1,0};
int dy[4] = {0,1,0,-1};
int board[105][105];
queue<pair<int,char>> changedir;
deque<pair<int,int>> snake;
int n,k,l,dir,x,y,ax,ay,ntime;
char ndir;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  dir = 1;
  cin >> n >> k;
  for (int i = 0; i < k; ++i){
    cin >> ax >> ay;
    board[ax][ay] = 'a';
  }
  cin >> l;
  for (int i = 0; i <l; ++i)
  {
    cin >> ntime >> ndir;
    changedir.push({ntime,ndir});
  }
  int time = 0;
  board[1][1] = 1;
  snake.push_front({1,1});
  while (1)
  {
    time++;
    pair<int,int> cur = snake.front();
    int nx = cur.X + dx[dir];
    int ny = cur.Y + dy[dir];
    if (nx ==0 || ny ==0 || nx > n|| ny > n || board[nx][ny] == 1){
      cout << time; return(0);
    }
    snake.push_front({nx,ny});
    if (board[nx][ny] != 'a')
    {
      pair<int,int> back = snake.back();
      board[back.X][back.Y] = 0;
      snake.pop_back();
    }
    board[nx][ny] = 1;
    if (changedir.front().first == time)
    {
      if (changedir.front().second == 'D') dir = (dir + 1)%4;
      if (changedir.front().second == 'L') dir = (dir + 3)%4;
      changedir.pop();
    }
  }
}