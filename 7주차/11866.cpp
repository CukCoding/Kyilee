//BOJ 11866 : 요세푸스 문제 0
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int n, k;
bool vi[1001];

int main()
{
    cin >> n >> k;

    cout << "<" << k;
    int idx = k; //커서 위치
    vi[idx] = 1; //출력했는지 확인하는 배열

    for (int i = 2; i <= n; i++)
    {
        int cnt = 0;
        while (1)
        {
            if (vi[idx] == 0)
                cnt++;
            if (cnt == k)
                break;
            if (idx + 1 > n)
                idx = 1;
            else
                idx++;
        }
        cout << ", " << idx;
        vi[idx] = 1;
    }
    cout << ">";
}
