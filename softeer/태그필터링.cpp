#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
int n,val,mn;
string k,v,str;
map<string,string> m[101];
void init()
{
  cin >> mn;
  int idx =1;
  while (idx <= mn)
  {
    cin >> str;
    str.append(",");
    bool flag = false;
    for (int i =0; i < str.size(); ++i)
    {
      if (str[i] == ',')
      {
        m[idx].insert({k,v});
        k.clear(); v.clear();
        flag = false;
      }
      else if (flag==false && str[i] == '=') flag = true;
      else if (flag== false)
      {
        k.push_back(str[i]);
      }
      else
      {
        v.push_back(str[i]);
      }
    }
    idx++;
  }
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  cin >> n;
  while (n--)// 1000
  {
    int total;
    cin >> total;
    vector<int> v;
    for (int i =0; i < total; ++i)
    {
      cin >> val;
      v.push_back(val);
    }
    sort(v.begin(), v.end()); //8
    int idx = v[0];
    bool ans = false;//150000000
    for (auto cur : m[idx])//50
    {
      set<string> sval;
      bool flag = true;
      sval.insert(cur.second);
      for (int i =1; i < v.size();++i)//50
      {
        auto it = m[v[i]].find(cur.first);
        if (it == m[v[i]].end()){
          flag =false;
          break;
        }
        sval.insert(it->second);
      }
      if (flag == false) continue;
      for (int i = 1; i <= mn; ++i)//100
      {
        if (binary_search(v.begin(),v.end(), i)) continue;//800
        auto it = m[i].find(cur.first);
        if (it != m[i].end())
        {
          auto sit = sval.find(it->second);
          if (sit != sval.end())
          {
            flag = false;
            break;
          }
        }
      }
      if (flag == false) continue;
      cout << "yes" << '\n';
      ans = true;
      break;
    }
    if (ans == false) cout << "no" << '\n';
  }
}
/*
5
x==
x=A
x=B
x==
x=x
9
5 1 2 3 4 5
1 1
2 1 2
2 1 4
3 1 4 5 
3 2 3 5
3 1 3 4
1 4
4 1 2 3 4

9
state=Deployed,loc=ulsan,role=web
loc=seoul,state=Deployed=,role=db=
state=Deployed,loc=daejeon,role=db
state=Building,loc=daejeon
loc=seoul,state=Deployed,role=web
loc=seoul,state=Building
state=Deployed,loc=daejeon,role=web
state=Failed,loc=daejeon
state=Failed,loc=ulsan
10
4 1 3 5 7
5 5 9 2 1 6
2 2 3
5 1 2 3 5 7
4 2 4 6 8
6 4 5 7 1 2 3
3 4 8 9
4 4 5 7 9
4 4 6 8 9
8 1 2 3 4 5 6 7 8
*/