//하노이 탑
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
void func(int a, int b, size_t n)
{
  if (n == 1){
    cout << a << ' ' << b << '\n';
    return ;
  }
  func(a, 6 - b - a, n - 1);
  cout << a << ' ' << b << '\n';
  func(6 - a-b, b, n -1);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  size_t n;
  cin >> n;
  
  cout << (1 << n) - 1 << '\n';
  func(1, 3, n);
}