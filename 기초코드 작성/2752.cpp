#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v(3);
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  cout << v[0] << " "<< v[1] << " "<< v[2];
}