#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
vector<tuple<int,int,int>> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  v.push_back({0,0,0});
  int x,y,z;
  tie(x,y,z) = v[0];
  x =1; y=2;
  cout << get<0>(v[0]);
  cout << get<1>(v[0]);
  cout << get<2>(v[0]);
}