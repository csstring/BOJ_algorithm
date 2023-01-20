#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[7];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[0] = 1;
  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 0;
  arr[4] = 1;
  arr[5] = 0;
  cin >> n;
  cout << (arr[(n-1) % 6 ] ? "SK" : "CY");
}