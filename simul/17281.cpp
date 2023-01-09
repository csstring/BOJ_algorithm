#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans,n;
int board[52][10];
int arr[10];
const int bitm = 15;
const int bitone = 1;
const int bitarr[4]= {16,32,64,128};
vector<int> player = {2,3,4,5,6,7,8,9};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i < n; ++i)
    for (int j =1; j< 10; ++j)
      cin >>board[i][j];
  arr[4] = 1;
  do {
    int j =0;
    for (int i =1;i <10; ++i)
    {
      if (i == 4) continue;
      arr[i] = player[j++];
    }
      int score = 0;
      int curP = 0;
      for (int l = 0; l < n; ++l)
      {
        int base = 1;
        int outCount = 0;
        while (outCount != 3)
        {
          curP += 1;         
          if (curP == 10) curP = 1;
          if (board[l][arr[curP]] == 0){
            outCount++;
            continue;
          }
          base = base | bitone;
          if (board[l][arr[curP]]) base = base << board[l][arr[curP]];
          if (base < 16) continue;
          for (int i = 0; i <4; ++i)
            if (base & bitarr[i]) score++;
          base = base & bitm;
        }
      }
      ans = score > ans ? score : ans;
  }while(next_permutation(player.begin(), player.end()));
  cout << ans;
}