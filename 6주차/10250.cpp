#include <bits/stdc++.h>

using namespace std;
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        int h, w, n, cheng, ho;
        cin >> h >> w >> n;
        //층수구하기
        if (n % h == 0)
        {
            cheng = h;
            ho = n / h;
        }
        else
        {
            cheng = n % h;
            ho = n / h + 1;
        }
        cout << cheng;
        if (ho < 10)
            cout << 0 << ho << "\n";
        else
            cout << ho << "\n";
    }
}
