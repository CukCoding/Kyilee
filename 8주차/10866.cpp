#include <bits/stdc++.h>

using namespace std;
int n, num, arr[200005], stidx = 10000, edidx = 10000; //st front 있는 위치
string order;
bool isempty()
{
    if (stidx == edidx)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> order;
        if (order == "push_back")
        {
            cin >> num;
            arr[edidx] = num;
            edidx++;
        }
        else if (order == "push_front")
        {
            cin >> num;
            stidx--;
            arr[stidx] = num;
        }
        else if (order == "pop_back")
        {
            if (!isempty())
            {
                cout << arr[edidx - 1] << "\n";
                edidx--;
            }
            else
                cout << "-1\n";
        }
        else if (order == "pop_front")
        {
            if (!isempty())
            {
                cout << arr[stidx] << "\n";
                stidx++;
            }
            else
                cout << "-1\n";
        }
        else if (order == "front")
        {
            if (!isempty())
            {
                cout << arr[stidx] << "\n";
            }
            else
                cout << "-1\n";
        }
        else if (order == "back")
        {
            if (!isempty())
            {
                cout << arr[edidx - 1] << "\n";
            }
            else
                cout << "-1\n";
        }
        else if (order == "size")
        {
            cout << edidx - stidx << "\n";
        }
        else if (order == "empty")
        {
            if (isempty())
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}