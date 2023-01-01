#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

size_t func(const size_t a, const size_t b, const size_t c)
{
  if (b == 1)
    return a % c;
  size_t val = func(a, b /2, c);
  val = val * val % c;
  if (b % 2 == 0)
    return val;
  else
    return (val * a) % c;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  size_t a,b,c;
  cin >> a >> b >> c;
  cout << func(a,b,c);
}