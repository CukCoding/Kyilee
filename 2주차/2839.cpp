//
//  main.cpp
//  2839
//
//  Created by 뜽효니 on 2022/01/06.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n,share=0, rest=0, sugar=0;
int main() {
    cin >> n;
    if ( n%5 ==0){
        cout << n/5 << "\n";
    }
    else{
        share = n/5;
        rest = n%5;
        while(true){
            if( rest %3 ==0){
                cout << share+(rest/3) << "\n";
                break;
            }
            else{
                share--;
                if(share ==-1){
                    cout <<-1<<'\n';
                    break;
                }
                rest+=5;
            }
        }
    }
}
