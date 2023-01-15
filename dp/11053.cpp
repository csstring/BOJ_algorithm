#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[1000001];
int c[1000001];
int n,ans,cnt,tcnt;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fill(c,c +n,1);
  for (int i =0; i <n; ++i)
    cin >> arr[i];
  for (int i =1; i < n; ++i)
  {
    for (int j = i -1; j >= 0; --j)
    {
      if (arr[j] >= arr[i]) continue;
      if (c[j] < c[i]) continue;
      c[i] = c[j] + 1;
    }
  }
  cout << *max_element(c, c+ 1000000);
}