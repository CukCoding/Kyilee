// BOJ 5073: 삼각형과 세 변
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        cin >> a >> b >> c;
        if (a == b && b == c && c == 0) //두개로만 비교가능
            break;
        //끝낸다!
        //삼각형인지 확인하는 중
        int mx = max(b, c);
        int mi = min(b, c);
        if (mx < a) //a가 제일큼
        {
            if (mi + mx <= a)
            {
                cout << "Invalid\n";
                continue;
            }
        }
        else
        {
            if (a + mi <= mx)
            {
                cout << "Invalid\n";
                continue;
            }
        }

        //이제 어떤 삼각형인지 판단
        if (a == b && b == c)
        {
            cout << "Equilateral\n";
            continue;
        }
        if (a == b || b == c || a == c)
        {
            cout << "Isosceles\n";
            continue;
        }
        cout << "Scalene\n";
    }
}