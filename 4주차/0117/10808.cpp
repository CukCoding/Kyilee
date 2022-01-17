//
//  10808: 알파벳 개수
//
//  Created by 뜽효니 on 2022/01/17.
//

#include <iostream>
#include <string>

using namespace std;

int alpha[26];
//전역변수에 선언하면 자동 0으로 초기화 됨!
int main(){
    ios::sync_with_stdio(); cin.tie(); cout.tie();
    string str;
    cin >> str;
    for(int i=0; i< str.size();i++){
        int tmp= str[i]-'a';
        //아스키코드 활용할 줄 알아야해!!!!!!
        alpha[tmp]++;
    }
    for(int i=0; i<26; i++) cout << alpha[i]<<" ";
    cout<< "\n";
}
