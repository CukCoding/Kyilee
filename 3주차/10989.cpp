//  main.cpp
//  10989 : 수 정렬하기3
//70%에서 시간초과ㅠㅠㅠㅠ
//입출력 조건 안달아줘서 시간초과 남!!!!!! 꼭 달아주기!!!!


#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cnt[10005]={0,}; //10000번 연산
int cmp=0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>> tmp;
        cnt[tmp]++;
    }//O(N)
    for(int i=1; i<=10000; i++){
        if(cnt[i] != 0){
            for(int j=0; j<cnt[i]; j++) {
                cout << i <<"\n";
                cmp++;
            }
        }
        if(cmp ==n)
            break;
    }
}
