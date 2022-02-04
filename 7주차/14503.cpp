// BOJ 14503 : 로봇청소기

#include <iostream>

using namespace std;
int space[51][51]; //0 청소안함, 1 벽, 2 청소함
int r, c, d;       //0=행, 1=열, 2=방향
int clean, cnt;    //clean 청소한 칸 cnt 다돌았는지 확인
int n, m;

int main()
{
    cin >> n >> m;

    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> space[i][j];
    //--------입력 끝!

    while (1)
    {
        //0이면? 청소하기
        if (space[r][c] == 0)
        {
            clean++;
            cnt = 0;
            space[r][c] = 2;
        }

        //네방향 다 돌아봤는데 없잖아
        if (cnt == 4)
        {
            //뒤쪽이 벽인지 확인
            if ((d == 0 && space[r + 1][c] == 1) ||
                (d == 1 && space[r][c - 1] == 1) ||
                (d == 2 && space[r - 1][c] == 1) ||
                (d == 3 && space[r][c + 1] == 1))
                break;

            //후진후진
            if (d == 0)
                r = r + 1;
            else if (d == 1)
                c = c - 1;
            else if (d == 2)
                r = r - 1;
            else
                c = c + 1;
            cnt = 0;
        }
        //북쪽이고 왼쪽에 청소할곳 있음
        if (d == 0 && space[r][c - 1] == 0)
        {
            c = c - 1;
            d = 3;
        }
        //동쪽이고 왼쪽에 청소할곳 있음
        else if (d == 1 && space[r - 1][c] == 0)
        {
            r = r - 1;
            d = 0;
        }
        //남쪽이고 왼쪽에 청소할곳 있음
        else if (d == 2 && space[r][c + 1] == 0)
        {
            c = c + 1;
            d = 1;
        }
        //서쪽이고 왼쪽에 청소할곳 있음
        else if (d == 3 && space[r + 1][c] == 0)
        {
            r = r + 1;
            d = 2;
        }
        //왼쪽이 청소했네?
        else
        {
            //왼쪽방향으로 계속 돌기
            if (d == 0)
                d = 3;
            else
                d--;
            cnt++;
        }
    }

    cout << clean << "\n";
}
