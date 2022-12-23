#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c, side, line;

  cin >> line;
  for (int i = 0; i < line; ++i)//0 3 5 8 0 1  
  {
    c = line * 2 - 1;
    side = (c - (2 * i + 1))/2;
    for (int j = 0; j < c - side; ++j)
    {
      if (j >= side)
        cout << "*";
      else
        cout << " ";
    }
    cout << '\n';
  }
}