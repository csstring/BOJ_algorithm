#include <iostream>
using namespace std;
int b[5000];
int n,cur;
size_t ans;
int getc(int x)
{
  int tmp = 0;
  for (int i =x+1; i <n; ++i)
    if (b[i] < b[x]) tmp++;
  return tmp;
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i) cin >> b[i];
  for (int i=0; i <n-2; ++i)
  {
    cur = getc(i);
    for (int j =i+1; j <n-1; ++j)
    {
      if (cur == 0) break;
      if (b[j] < b[i]){
        cur--;
        continue;
      } 
      ans += cur;
    }
  }
  cout << ans;
}