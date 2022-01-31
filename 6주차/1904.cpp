
//BOJ : 1904 01타일
#include <bits/stdc++.h>
#define mod 15746
using namespace std;

int n;
int arr[1000001] = {
    0,
    1,
    2,
};
int fn(int left)
{
    if (left >= 0 && left <= 2)
        return arr[left];
    if (arr[left] != 0)
        return arr[left];

    //mod값보다 작은 수들만 들어갈 수 있게
    arr[left] = (fn(left - 1) + fn(left - 2)) % 15746;
    return arr[left];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << fn(n) % 15746;
}