#include <iostream>
#include <string>
#include <iterator>
#include <stack>
using namespace std;
int c, val, cnt;
long long total;
stack<pair<int,int>> st;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c;
    for (int i = 0; i < c; ++i)
    {
        cnt = 1;
        cin >> val;
        while (st.size() > 0 && st.top().first <= val)
        {
            total += st.top().second;
            if (st.top().first == val)
                cnt += st.top().second;
            st.pop();
        }
        if (st.size() > 0)
            total++;
        st.push({val, cnt});
    }
    cout << total;
}