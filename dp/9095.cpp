#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[1000001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  const size_t tmp = 1000000009;
  for (size_t i=4; i <1000001 ;++i)
  {
    arr[i] = (arr[i-2] + arr[i-1] +arr[i-3]) % tmp;
  }
  size_t n,t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cout << arr[n] % tmp << '\n';
  }
}