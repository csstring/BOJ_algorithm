#include <iostream>
#include <algorithm>
using namespace std;
int val[5];
int avl;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 5; ++i)
  { 
    cin >> val[i];
    avl += val[i];
  }
  cout << avl / 5 << '\n';
  sort(val, val+5);
  cout << val[2];
}