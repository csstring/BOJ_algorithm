#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
#define X first
#define Y second
#define N 0
#define S 1
int k,ans;
deque<int> dq[4];
pair<int,int> rot[4];
void ft_rot(int num, int dir)
{
  int temp;
  if (dir == 1)
  {
    temp = dq[num].back();
    dq[num].push_front(temp);
    dq[num].pop_back();
  }
  else
  {
    temp = dq[num].front();
    dq[num].push_back(temp);
    dq[num].pop_front();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  char val = 0;
  for (int i =0; i < 4; ++i){
    for (int j =0; j <8; ++j){
      cin >> val;
      dq[i].push_back(val - 48);
    }
  }
  int num,dir;
  cin >> k;
  for (int i = 0; i < k;++i)
  {
    cin >> num >> dir;
    num--;
    int vis[5] = {};
    for (int j =0; j <4; ++j)
      rot[j].first = 0;
    for (int j =0; j < 4;++j)
    {
      if (j %2 == num%2) rot[j].second = dir;
      else rot[j].second = -1*dir;
    }
    queue<int> q;
    vector<int> v;
    q.push(num);
    vis[num] = 1;
    v.push_back(num);
    while (!q.empty())
    {
      int cur = q.front(); q.pop();
      for (int nx : {cur + 1, cur -1})
      {
        if (nx < 0 || nx > 3) continue;
        if (vis[nx]) continue;
        if ((nx > cur && dq[nx][6] != dq[cur][2]) || (nx < cur && dq[cur][6] != dq[nx][2])){
          v.push_back(nx);
          q.push(nx);
          vis[nx] = 1;
        }
      }
    }
    for (int nx : v)
      ft_rot(nx, rot[nx].second);
  }
  for (int i =0; i < 4; ++i)
    ans += dq[i].front() << i; 
  cout << ans;
}