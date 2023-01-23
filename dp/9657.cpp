//돌게임3
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[1001];//0선 1후
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 0;
  arr[4] = 0;
  cin >> n;
  for (int i = 5; i <= n; ++i)
  {
    for (int j : {1,3,4})
    {
      if (arr[i-j] == 1){
        arr[i] = 0;
        break;
      }
      else arr[i] = 1;
    }
  }
  if (!arr[n]) cout << "SK";
  else cout << "CY";
}