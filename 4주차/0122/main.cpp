//
//  main.cpp
//  barkingDog
//
//  Created by 뜽효니 on 2022/01/15.
//

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int func1(int n){
    int cnt=0;
    for (int i=0; i<n; i++){
        if( i%3 ==0 || i%5 ==0){
            cnt += i;
        }
    }
    return cnt;
    
}
//시간복잡도 n

int func2(int arr[], int n){
    
    for (int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(i+j == 100) return 1;
        }
    }
    return 0;
}
//시간복잡도 n^2

//위코드 이렇게 줄일 수 있음
//int func2(int arr[], int n){
//    for (int i=0; i<n; i++)
//        for(int j=i+1; j<n; j++)
//            if(i+j == 100) return 1;
//    return 0;
//}

int func3(int n){
    for (int i=1; i<40000; i++){
        if(i*i==n) return 1;
    }
    return 0;
}

//1. 10억까지 돌린다, 2.sqrt를 쓴다 3.10억의 제곱수를 찾는다

//func3 답
int func3ANS(int n){
    for (int i=1; i*i<= n; i++){
        if(i*i==n) return 1;
    }
    return 0;
}


int func4(int n){
    int two=2;
    while(two <= 100000000){
        if(two>= n){
            return two;
        }
        else two*=2;
    }
    return 0;
}
//logN 이 시간복잡도??

int func4ANS(int n){
    int two=1;
    while(2*two <= n) break;
    return two;
}
