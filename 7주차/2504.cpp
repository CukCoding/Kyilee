#include <bits/stdc++.h>
#include <stack>
using namespace std;
string st;
int ans, num = 1;
stack<char> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> st;
    for (int i = 0; i < st.size(); i++)
    {
        //tmp == 들어온 애
        char tmp = st[i];

        if (tmp == '(')
        {
            num *= 2;
            arr.push(tmp);
        }
        else if (tmp == '[')
        {
            num *= 3;
            arr.push(tmp);
        }

        //pop조건
        else if (tmp == ')' || tmp == ']') //왜 "" 는 되고 ''는 안되냐?
        {
            //짝 맞는지 확인
            if (!arr.empty() && arr.top() == '(' && tmp == ')')
            {
                if (st[i - 1] == '(')
                {
                    ans += num;
                }
                num /= 2;
                arr.pop();
            }
            else if (!arr.empty() && arr.top() == '[' && tmp == ']')
            {
                if (st[i - 1] == '[')
                {
                    ans += num;
                }
                num /= 3;
                arr.pop();
            }
            else //empty이거나 짝이 안맞음
            {
                cout << "0\n";
                return 0;
            }
        }
    }
    if (!arr.empty())
        cout << "0\n";
    else
        cout << ans << "\n";
}