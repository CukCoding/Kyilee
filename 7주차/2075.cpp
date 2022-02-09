#include <bits/stdc++.h>

using namespace std;
int n;
// vector<int> v;
// arr[2300000];
priority_queue<int, vector<int>, greater<>> pq; //사이즈 고정을 내가 n으로 하기로 했다!

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        int tmp;
        cin >> tmp;

        if (pq.size() < n)
            pq.push(tmp);
        else if (pq.top() < tmp)
        {
            pq.pop();
            pq.push(tmp);
        }
    }

    cout << pq.top();
}