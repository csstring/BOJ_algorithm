#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[1001];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr[1] = 1;
  arr[2] = 3;
  const int tmp = 10007;
  for (int i = 3; i <=n; ++i)
  {
    arr[i] = (arr[i-1] + arr[i-2] * 2) %tmp;
  }
  cout << arr[n];
}