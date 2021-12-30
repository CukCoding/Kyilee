//
//  BOJ 1003 : 피보나치 함수


#include <iostream>
#include <algorithm>
int fibo[50] = {0,1,};


using namespace std;
int fi(int n) {
    if (n == 0 || n==1) {
        return n;
    }
    if(fibo[n]) return fibo[n];
    else return fibo[n]= fi(n-1)+fi(n-2);
}

int main() {
    ios_base :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        
        if(n==0){
            cout << "1 0\n";
        }
        else if(n==1){
            cout << "0 1\n";
        }
        else{
            cout << fi(n-1) << " " << fi(n)<< '\n';
        }
    }
    
}
