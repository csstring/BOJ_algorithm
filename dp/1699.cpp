//제곱수의합
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[100001];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =1; i <= n; ++i)
  {
    arr[i] = i;
    for (int j = 1; j*j <= i; ++j)
    {
      arr[i] = min(arr[i], arr[i - j*j] + 1);
    }
  }
  cout << arr[n];
}