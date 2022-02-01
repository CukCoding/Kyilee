// BOJ 2747 : 캥거루 세마리

#include <bits/stdc++.h>

using namespace std;

int a, b, c, dist;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    dist = max(b - a, c - b);
    cout << dist - 1;
}