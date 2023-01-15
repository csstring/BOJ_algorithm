#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[301][3];
int Count[301];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n;
  for (int i =1; i<= n; ++i)
    cin >> Count[i];
  arr[1][1] = Count[1];
  arr[1][2] = 0;
  arr[2][1] = Count[2];
  arr[2][2] = arr[1][1] + Count[2];
  for (int i =3; i <= n; ++i)
  {
    arr[i][1] = max(arr[i-2][1], arr[i-2][2]) + Count[i];
    arr[i][2] = arr[i-1][1] + Count[i];
  }
  cout << max(arr[n][1], arr[n][2]);
}