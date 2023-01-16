#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[101];
int n,t;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 1;
  arr[4] = 2;
  arr[5] = 2;
  for (int i =6; i <=100; ++i)
  {
    arr[i] = arr[i-1] +arr[i-5];
  }
  while (t--)
  {
    cin >>n;
    cout << arr[n] << '\n';
  }
}