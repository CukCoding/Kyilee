// BOJ 2747 : 피보나치 수
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[50] = {
    0,
    1,
};

int fibo(int n)
{
    if (n == 1 || n == 0 || arr[n] != 0)
    {
        return arr[n];
    }
    arr[n] = fibo(n - 2) + fibo(n - 1);
    return arr[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << fibo(n);
}