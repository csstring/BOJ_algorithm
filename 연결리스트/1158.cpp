#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;
list<int> List;
int k,n;
list<int>::iterator Pos;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i < n + 1; ++i)
    List.push_back(i);
  Pos = List.begin();
  cout << '<';
  for (int j = 0; j < n; ++j)
  {
    for (int c = 0; c < k - 1; ++c)
    {
      Pos++;
      if (Pos == List.end())
        Pos = List.begin();
    }
    if (List.size() > 1)
      cout << *Pos << ", ";
    else 
      cout << *Pos << '>';
    Pos = List.erase(Pos);
    if (Pos == List.end())
        Pos = List.begin();
  }
}