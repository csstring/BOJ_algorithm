#include <iostream>
#include <cmath>
using namespace std;
int k, n, s, y, arr[2][7], total;
float temp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
  {
    cin >> s >> y;
    arr[s][y]++;
  }
  for (int i = 0; i < 2;++i)
    for (int j = 1; j < 7; ++j)
    {
      total += ceil((float)arr[i][j] / k);
    }
  cout << total;
}