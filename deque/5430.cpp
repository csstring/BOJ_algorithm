#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <deque>
using namespace std;
#define off 0
#define on 1
string arr, P, temp;
deque<int> dq;
int T, n, rswich, error_flag;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (int i = 0; i < T; ++i)
  {
    rswich = off; error_flag = off;
    dq.clear();
    cin >> P >> n;
    getline(cin, temp, '[');
    for (int i = 1; i < n; ++i)
    {
      getline(cin, temp, ',');
      dq.push_back(stoi(temp));
    }
    getline(cin, temp, ']');
    if (temp.size())
      dq.push_back(stoi(temp));
    for (string::iterator it = P.begin(); it != P.end(); ++it)
    {
      if (*it == 'R')
        rswich = (rswich + 1) % 2;
      else
      {
        if (!dq.size())
        {
          error_flag = on;
          break;
        }
        if (rswich == on)
          dq.pop_back();
        else
          dq.pop_front();
      }
    }
    if (error_flag)
      cout << "error\n";
    if (rswich == on)
    {
      cout << '[';
      for (deque<int>::reverse_iterator rPos = dq.rbegin(); rPos != dq.rend(); ++rPos)
      {
        cout << *rPos;
        if (rPos + 1 != dq.rend())
          cout << ',';
      }
      cout << "]\n";
    }
    else
    {
      cout << '[';
      for (deque<int>::iterator Pos = dq.begin(); Pos != dq.end(); ++Pos)
      {
        cout << *Pos;
        if (Pos + 1 != dq.end())
          cout << ',';
      }
      cout << "]\n";
    }
  }
}