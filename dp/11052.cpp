#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[1001];
int p[1001];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i=1; i <= n; ++i)
    cin >> p[i];
  for (int i =0; i <n; ++i)
  {
    for (int j =1; i+j <=n; ++j)
    {
      if (arr[i] + p[j] > arr[i+j])
        arr[i+j] = arr[i] +p[j];
    }
  }
  cout << arr[n];
}