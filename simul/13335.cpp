#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
#define X first
#define Y second
queue<int> bridge;
queue<int> truck;
int n,w,l,ans, totalW;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w >>l;
  int tw;
  for (int i =0; i < n; ++i){
    cin >> tw;
    totalW += tw;
    truck.push(tw);
  }
  for (int i = 0; i < w; ++i){
    bridge.push(0);
  }
  int curW = 0;
  int exitW = 0;
  while (exitW != totalW)
  {
    exitW += bridge.front();
    curW -= bridge.front();
    bridge.pop();
    if (truck.size() > 0 && curW + truck.front() <= l){
      bridge.push(truck.front());
      curW += truck.front(); 
      truck.pop();
    }
    else
      bridge.push(0);
    ans++;
  }
  cout << ans;
}
