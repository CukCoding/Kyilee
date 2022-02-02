// BOJ 2579: 계단오르기

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int score[303];
int arr[303][3];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    arr[1][1] = score[1];
    arr[1][2] = 0;
    arr[2][1] = score[2];
    arr[2][2] = score[1] + score[2];

    for (int i = 3; i <= n; i++)
    {
        arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + score[i];
        arr[i][2] = arr[i - 1][1] + score[i];
    }
    cout << max(arr[n][1], arr[n][2]);
}