#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,val;
int arr[10001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >>val;
    arr[val]++;
  }
  for (int i = 1; i <= 10000; ++i)
  {
    if (arr[i] == 0) continue;
    val = arr[i];
    for (int j =0 ; j < val; ++j)
      cout << i << '\n';
  }
}