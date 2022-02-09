#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v1, v2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp); //원본
        v2.push_back(tmp); //비교
    }

    sort(v2.begin(), v2.end());
    //중복원소 제거 함수 unique -> 벡터로 해야함
    //unique 중복값 삭제, 남은 빈공간은 이전값 채워넣음, 반환값은 unique 하고 남은 빈공간 처음 주소
    //erase 빈공간 쭈르륵 삭제.
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    //복사~
    for (int i = 0; i < n; i++)
    {
        //이진탐색 lower_bound (비교배열시작,끝,순서찾고자하는 값)
        //find 는 선형탐색이라 o(N),
        auto it = lower_bound(v2.begin(), v2.end(), v1[i]);
        // it에서 cv벡터의 시작 주소값을 빼준 값이 답
        cout << it - v2.begin() << " ";
    }
}