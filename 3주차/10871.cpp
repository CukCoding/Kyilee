//  main.cpp
//  0x01
//
//  Created by 뜽효니 on 2022/01/16.
// 10871번 :X보다 작은 수

#include <iostream>
using namespace std;

int main() {
    int n,x;
    cin >> n>>x;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp <x) cout << tmp <<" ";
    }
    
}
