#include <bits/stdc++.h>

using namespace std;

int t, n, m;
queue<pair<int, int>> q;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    while (t--)
    {
        //초기화
        while (!pq.empty())
            pq.pop();
        while (!q.empty())
            q.pop();
        int cnt = 0;

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            q.push(make_pair(tmp, i));
            pq.push(tmp);
        }

        while (1)
        {
            int val = q.front().first;
            int idx = q.front().second;
            q.pop();

            if (pq.top() == val)
            {
                pq.pop();
                cnt++;
                if (idx == m)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else
                q.push({val, idx});
        }
    }
}