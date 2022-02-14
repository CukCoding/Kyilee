#include <bits/stdc++.h>

using namespace std;
int n;
int arr[1001] = {
    0,
    1,
    2,
};

int dp(int n)
{
    if (n == 0 || n == 1 || arr[n] != 0)
        return arr[n];
    else
    {
        arr[n] = (dp(n - 1) + dp(n - 2)) % 10007;
        return arr[n];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << dp(n);
}