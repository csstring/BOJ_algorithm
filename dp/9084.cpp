#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,t,m,ans;
int coin[20];
int arr[10001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i =0; i<n; ++i)
      cin >> coin[i];
    cin >> m;
    fill(arr, arr+m+1,0);
    arr[0] = 1;
    for (int i =0; i <n; ++i)
    {
      for (int j = coin[i]; j <=m; ++j)
      {
        arr[j] += arr[j-coin[i]];
      }
    }
    cout << arr[m] << '\n';
  }
}