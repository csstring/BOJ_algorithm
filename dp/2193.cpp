#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[91][2];
size_t n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr[1][1] = 1;
  for (int i = 2; i<= n; ++i)
  {
    arr[i][1] = arr[i-1][0];
    arr[i][0] = arr[i-1][0] + arr[i-1][1];
  }
  cout << arr[n][0] + arr[n][1];
}