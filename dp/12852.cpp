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
int root[1000001];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr[1] = 0;
  root[1] =1;
  for (int i = 2; i <=n; ++i)
  {
    arr[i] = arr[i-1] + 1;
    root[i] = i-1;
    if (i % 3 == 0) {
      if (arr[i/3] +1 < arr[i]){
        arr[i] = arr[i/3] +1;
        root[i] = i/3;
      }
    }
    if (i% 2 ==0) {
      if (arr[i/2] +1 < arr[i]){
        arr[i] = arr[i/2] +1;
        root[i] = i/2;
      }
    }
  }
  cout << arr[n] << '\n';
  int tmp = n;
  while (tmp != 1)
  {
    cout << tmp << ' ';
    tmp = root[tmp];
  }
  cout << 1;
}