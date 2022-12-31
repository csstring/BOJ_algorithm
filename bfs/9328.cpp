#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int test_case, n,m;
char board[102][102];
bool vis[102][102];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> test_case;
  for (int l=0; l < test_case; ++l)
  {
    int ans = 0;
    cin >> n >> m;
    queue<pair<int,int>> door[26];
    queue<pair<int,int>> q;
    int key[26] = {};
    for (int i = 0; i <= n + 1; ++i){
      fill(board[i], board[i] + m + 2, 0);
      fill(vis[i], vis[i] + m + 2, 0);
    }
    for (int i = 1; i <= n; ++i){
      for (int j = 1; j <= m; ++j){
        cin >> board[i][j];
      }
    }
    string prekey;
    cin >> prekey;
    for (int i = 0; i < prekey.size(); ++i){
      if (prekey[i] != '0') key[prekey[i] - 'a'] = 1;
    }
    q.push({0,0});
    vis[0][0] = 1;
    while (!q.empty())
    {
      pair<int,int> cur = q.front(); q.pop();
      for (int dir = 0; dir < 4; ++dir)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx > n + 1|| ny > m + 1) continue;
        if (board[nx][ny] == '*' || vis[nx][ny] == 1) continue;
        vis[nx][ny] = 1;
        if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z')
        {
          int k = board[nx][ny] - 'a';
          key[k] = 1;
          while (!door[k].empty()){
            pair<int,int> temp_door = door[k].front(); door[k].pop();
            q.push({temp_door.X, temp_door.Y}); 
          }
        }
        else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z')
        {
          int k = board[nx][ny] - 'A';
          if (!key[k])
          {
            door[k].push({nx,ny});
            continue;
          }
        }
        else if (board[nx][ny] == '$') 
          ans++;
        q.push({nx,ny});
      }
    }
    cout << ans << '\n';
  }
}