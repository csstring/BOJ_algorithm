//타일채우기
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[31];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[0] = 1;
  arr[1] = 0;
  arr[2] = 3;
  arr[3] = 0;
  cin >> n;
  for (int i =4; i <= n; ++i)
  {
    arr[i] = arr[i-2] *3;
    for (int j = i -4; j >=0; j -= 2)
    {
      arr[i] += arr[j] * 2;
    }
  }
  cout << arr[n];
}