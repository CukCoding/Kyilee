#include <bits/stdc++.h>

using namespace std;
int n, arr[55], tmp;
long long sum;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n); //O(NlogN), quick sort 사용함

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            if (tmp == 0)
            {
                tmp = arr[i];
            }
            else
            {
                sum += tmp * arr[i];
                tmp = 0;
            }
        }
        else //양수일때요 선생님
        {
            if (arr[i] == 1)
            //1은 더해야 최대가 나온다!!!
            {
                sum += 1;
                continue;
            }
            if (arr[i] > 1 && arr[i - 1] <= 1) //1이상인 수로 바뀐 시점!
            {
                //남은거 더해주기
                sum += tmp;
                tmp = 0;

                if ((n - i) % 2 == 1)
                //남은갯수가 홀수면 첫번째는 그냥더하기
                {
                    sum += arr[i];
                    continue;
                }
            }
            if (tmp == 0)
                tmp = arr[i];
            else
            {
                sum += tmp * arr[i];
                tmp = 0;
            }
        }
    }
    if (tmp != 0)
        sum += tmp;
    cout << sum;
}