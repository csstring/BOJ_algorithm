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
int n;
const int mod = 15746;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr[1] = 1;
  arr[2] = 2;
  for (int i =3; i <= n; ++i)
  {
    arr[i] = (arr[i-2] + arr[i-1]) % mod;
  }
  cout << arr[n] % mod;
}