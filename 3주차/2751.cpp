//
//  main.cpp
//  2751
//
//  Created by 뜽효니 on 2022/01/16.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1000005];
int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n; i++) cout << arr[i]<<"\n";
}
