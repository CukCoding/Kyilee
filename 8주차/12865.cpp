#include <bits/stdc++.h>

using namespace std;
int n, k;
int wv[105][2], dp[105][100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> wv[i][0] >> wv[i][1]; //무게,가치

    for (int i = 1; i <= n; i++) //이전항 써야하니까
        for (int j = 1; j <= k; j++)
            if (j >= wv[i][0])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wv[i][0]] + wv[i][1]);
            else
                dp[i][j] = dp[i - 1][j];

    cout << dp[n][k];
}