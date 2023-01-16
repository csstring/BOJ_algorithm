#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[91];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[0] = 0;
  arr[1] = 1;
  for (int i =2; i <=90; ++i)
  {
    arr[i] = arr[i-1]+arr[i-2];
  }
  cin >> n;
  cout << arr[n];
}