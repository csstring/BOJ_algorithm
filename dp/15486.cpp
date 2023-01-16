#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int t[1500002];
int p[1500002];
int arr[1500002];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =1; i <= n; ++i)
    cin >> t[i] >> p[i];
  for (int i =n; i>= 1; --i)
  {
    if (t[i] + i <= n + 1)
    {
      arr[i] = max(arr[i+1], p[i] + arr[i + t[i]]);
    }
    else
      arr[i] = arr[i+1];
  }
  cout << *max_element(arr+1, arr+1+n);
}