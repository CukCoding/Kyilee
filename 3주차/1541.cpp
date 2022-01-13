//
//  그리디
// BOJ 1541 : 잃어버린 괄호
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string math;
string num;
int ans =0;
bool isMinus=false;


int main() {
    ios_base :: sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> math;

    for(int i=0; i<=math.size(); i++){
        if( math[i] == '+' || math[i] == '-' || math[i]=='\0'){//마지막 문자열 끝에 \0이 붙음
        //기호 들어왔을때
            
           
            if(isMinus==false) ans +=stoi(num); //지금 부호 붙었는지 확인
            else ans -=stoi(num);
            
            num="";//숫자 초기화
            
            if( math[i] == '-') isMinus = true;
        }
        else{
        //숫자일떄
            num += math[i]; //string 추가하면 배열처럼 채울 수 있음
        }
    }
    
    cout << ans <<"\n";
}



//string 도 vector 처럼 .size()를 쓸 수 있다
//문자열 끝에는 '\0'이 붙는다
//string은 배열처럼 += math[i]가 가능하다
