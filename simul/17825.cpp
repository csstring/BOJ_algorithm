//주사위 윷놀이
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int dx[5] = {1,2,3,4,5};
int dirarr[10];
int val,ans,maxSize;
vector<int> board[4];
vector<tuple<int,int,int>> horse = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
void boardinit()
{
  board[0] = {-1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0};
  board[1] = {10,13,16,19,25,30,35,40};
  board[2] = {20,22,24,25,30,35,40};
  board[3] = {30,28,27,26,25,30,35,40};
  maxSize = board[0].size();
  for (int i =1; i <4; ++i)
  {
    while (maxSize != board[i].size())
      board[i].push_back(0);
  }
}
bool poscheck(int x,int y,int h)
{
  if (board[x][y] <= 0) return true;
  for (int i = 0; i < 4; ++i)
  {
    if (i == h) continue;
    int nx,ny,s;
    tie(nx,ny,s) = horse[i];
    if (x == nx && y == ny) return false;
    if (board[x][y] == 25 && board[nx][ny] == 25) return false;
    if (y > 0 && ny > 0 && (board[x][y] == 30 && board[nx][ny] == 30)) return false;
    if (board[x][y] == 35 && board[nx][ny] == 35) return false;
    if (board[x][y] == 40 && board[nx][ny] == 40) return false;
  
  }
  return true;
}
void run(int k)
{
  if (k == 10)
  {
    int temp = 0;
    for (int i = 0; i <4; ++i){
      temp += get<2>(horse[i]);

    }
    ans = max(ans, temp);
    return;
  }
  for (int h = 0; h <4; ++h)
  {
    int x,y,score;
    int rx,ry,rscore;
    tie(x,y,score) = horse[h];
    rx =x; ry = y; rscore = score;
    if (board[x][y] == 0) continue;
    y += dirarr[k];
    if (y >= maxSize) y = maxSize - 1;
    if (x == 0 && board[x][y] == 10){
      x = 1; y = 0;
    }
    if (x == 0 && board[x][y] == 20){
      x = 2; y = 0;
    }
    if (x == 0 && board[x][y] == 30){
      x = 3; y = 0;
    }
    if (poscheck(x,y,h) == false) continue;
    score += board[x][y];
    horse[h] = {x,y,score};
    run(k+1);
    horse[h] = {rx,ry,rscore};
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  boardinit();
  for (int i = 0; i <10; ++i)
  {
    cin >> val;
    dirarr[i] = val;
  }
  run(0);
  cout << ans;
}