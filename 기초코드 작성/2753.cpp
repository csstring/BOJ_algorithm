#include <iostream>

using namespace std;
int y;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> y;
  if (y % 4 == 0 && (y % 400 == 0 || y % 100 != 0))
    cout << "1";
  else
    cout << "0";
}