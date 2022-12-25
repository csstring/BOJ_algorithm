#include <iostream>
#include <string>
#include <iterator>
#include <queue>
using namespace std;
string cmd;
queue<int> q;
int n, val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> cmd;
    if (cmd == "push")
    {
      cin >> val;
      q.push(val);
    }
    else if (cmd == "pop")
    {
      if (q.empty())
        cout << "-1\n";
      else
      {
        cout << q.front() << "\n"; 
        q.pop();
      }
    }
    else if (cmd == "size")
      cout << q.size() << "\n";
    else if (cmd == "empty")
    {
      if (q.empty())
        cout << "1\n";
      else
        cout << "0\n";
    }
    else if (cmd == "front")
    {
      if (q.empty())
        cout << "-1\n";
      else
      {
        cout << q.front() << "\n"; 
      }
    }
    else if (cmd == "back")
    {
      if (q.empty())
        cout << "-1\n";
      else
      {
        cout << q.back() << "\n"; 
      }
    }
  }
}