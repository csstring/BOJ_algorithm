#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;
int Count;
string src;
int main()
{
  list<int>::iterator pos;
  list<int> List;
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Count;
  for (int i = 0; i < Count; ++i)
  {
    cin >> src;
    List.clear();
    pos = List.begin();
    for (int j = 0; j < src.size(); ++j)
    {
      if (src[j] == '<')
      {
        if (pos != List.begin())
          pos--;
      }
      else if (src[j] == '>')
      {
        if (pos != List.end())
          ++pos;
      }
      else if (src[j] == '-')
      {
        if (pos != List.begin())
        {
          pos = List.erase(--pos);
        }
      }
      else
      {
        List.insert(pos, src[j]);
      }
    }
    for (list<int>::iterator it = List.begin(); it !=List.end(); ++it)
      cout << (char)*it;
    cout << '\n';
  }  
}