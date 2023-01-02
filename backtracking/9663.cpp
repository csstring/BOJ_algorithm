#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool vis1[30];//열
bool vis2[30];//x+y
bool vis3[30];//x-y+n+2?
int ans,n;
void run(int x)
{
  if (x == n){
    ans++; return;
  }
  for (int y = 0; y < n; ++y)
  {
    if (vis1[y] || vis2[x + y] || vis3[x - y + n + 1]) continue;
    vis1[y] = true;
    vis2[x + y] = true;
    vis3[x - y + n + 1] = true;
    run(x + 1);
    vis1[y] = false;
    vis2[x + y] = false;
    vis3[x - y + n + 1] = false;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  run(0);
  cout << ans;
}