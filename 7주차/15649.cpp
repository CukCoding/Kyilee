#include <bits/stdc++.h>

using namespace std;
bool visited[10];
int num[10];
int n, m;

int func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << num[i] << " ";
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            num[k] = i;
            visited[i] = true;
            // cout << i << "방문!\n";
            func(k + 1);
            visited[i] = false;
            // cout << i << "방문해제!\n";
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    func(0);
}
