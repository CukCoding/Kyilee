//
//  main.cpp
//  4796
//
//  Created by 뜽효니 on 2022/01/06.
//

#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c,cnt=0, num=1;

int main() {

    while(true){
        cin >> a >> b >> c;
        cnt=0;
        if ( a ==0 && b==0 && c==0) {
            break;
        }
        else{
            cnt = a *(c/b);
            if ( c%b < a){
                cnt += c%b;
            }
            else{
                cnt += a;
            }
//            cout << "Case " << num << ": " << cnt<<"\n";
            printf("Case %d: %d\n", num, cnt);
            num++;
        }
    }
    
}
