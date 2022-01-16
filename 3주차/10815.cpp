//
//  main.cpp
//  10815 : 숫자카드

#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[500005];
int find(int left,int right,int t){
    if(left>right) return 0;
    int mid= (left+right)/2;
    if(arr[mid]==t) return 1;
    else if (arr[mid]<t) return find(mid+1,right,t);
    else return find(left, mid-1,t);
}
                              
                              
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin>> tmp;
        cout <<find(0,n,tmp)<<" ";
    }
}
