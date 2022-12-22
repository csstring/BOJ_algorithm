#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a(3);
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a[0] >> a[1] >> a[2];
  if (a[0] == a[1]== a[2])
    cout << 10000 + a[0] * 1000;
  else if (a[0] != a[1] && a[0] != a[2] && a[1] != a[2])
    cout << *max_element(a.begin(), a.end()) * 100;
  else
  {
    sort(a.begin(),a.end());
    cout << 1000 + a[1] * 100;
  }
}