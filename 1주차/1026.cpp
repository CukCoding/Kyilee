//
//  main.cpp
//  1026
//  Created by 뜽효니 on 2021/12/30.

#include <iostream>
#include <algorithm>
using namespace std;

int a[55]={0,},b[55]={0,};
int cnt=0;
bool desc(int a, int b){
  return a > b;
}
int main() {
    ios_base :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int n;
    cin >> n;
    //입력받기
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(b, b+n, desc);
    
    for(int i=0; i<n; i++){
        cnt = cnt+ a[i]*b[i];
    }
    cout << cnt <<"\n";
}
