#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;
int Count;
char val, ldbp;
string src;
int main()
{
  list<char>::iterator pos;
  list<char> List;
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> src;
  for (int i = 0; i < src.size(); ++i)
    List.push_back(src[i]);
  pos = List.end();
  cin >> Count;
  for (int j = 0; j < Count; ++j)
  {
    cin >> ldbp;
    if (ldbp == 'P')
      cin >> val;
    if (ldbp == 'L')
    {
      if (pos != List.begin())
        pos--;
    }
    else if (ldbp == 'D')
    {
      if (pos != List.end())
        ++pos;
    }
    else if (ldbp == 'B')
    {
      if (pos != List.begin())
      {
        pos = List.erase(--pos);
      }
    }
    else
    {
      List.insert(pos, val);
    }
  }
  for (list<char>::iterator it = List.begin(); it !=List.end(); ++it)
    cout << *it;
}