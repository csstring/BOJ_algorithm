#include <iostream>
#include <cmath>
using namespace std;
int c, Time[20],y_val,m_val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> c;
  for (int i = 0; i < c; ++i)
    cin >> Time[i];
  
  float ex;
  for (int i = 0; i < c; ++i)
  {
    ex = (float)Time[i] / 30;
    y_val += (floor(ex) + 1) * 10;
    ex = (float)Time[i] / 60;
    m_val += (floor(ex) + 1) * 15;
  }
  if (y_val < m_val)
    cout << "Y "<< y_val;
  else if (y_val == m_val)
    cout << "Y M "<< y_val;
  else
    cout << "M " << m_val;
}