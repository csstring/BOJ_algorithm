#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
#define X first
#define Y second
int n, x,y;
vector<pair<int,int>> v;
bool ft_comp(pair<int,int> a, pair<int,int> b)
{
  if (a.Y != b.Y)
    return a.Y < b.Y;
  return a.X < b.X;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n ; ++i){
    cin >> x >> y;
    v.push_back({x,y});
  }
  stable_sort(v.begin(),v.end(), ft_comp);
  for (int i = 0; i <n; ++i){
    cout << v[i].X << ' ' <<v[i].Y << '\n';
  }
}