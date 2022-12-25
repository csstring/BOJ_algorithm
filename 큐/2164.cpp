#include <iostream>
#include <string>
#include <iterator>
#include <queue>
using namespace std;
queue<int> q;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n+1; ++i)
    q.push(i);
  while (q.size() != 1)
  {
    q.pop();
    q.push(q.front());
    q.pop();
  }
  cout << q.front();
}