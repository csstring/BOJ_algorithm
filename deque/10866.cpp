#include <iostream>
#include <string>
#include <iterator>
#include <deque>
using namespace std;
int n, val, j;
deque<int> dq;
string cmd;
string cmd_list[8] = {"push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back"};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0 ; i < n; ++i)
  {
    cin >> cmd;
    j = 0;
    while (cmd_list[j] != cmd)
      j++;
    switch (j)
    {
    case 0:
      cin >> val;
      dq.push_front(val);
      break;
    case 1:
      cin >> val;
      dq.push_back(val);
      break;
    case 2:
      if (!dq.empty())
      {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
      else
        cout << "-1\n";
      break;
    case 3:
      if (!dq.empty())
      {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
      else
        cout << "-1\n";
      break;
    case 4:
      cout << dq.size() << '\n';
      break;
    case 5:
      if (!dq.empty())
        cout << "0\n";
      else
        cout << "1\n";
      break;
    case 6:
      if (!dq.empty())
        cout << dq.front() << '\n';
      else
        cout << "-1\n";
      break;
    case 7:
      if (!dq.empty())
        cout << dq.back() << '\n';
      else
        cout << "-1\n";
      break;
    }
  }
}