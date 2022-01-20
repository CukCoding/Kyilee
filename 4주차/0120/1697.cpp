//

#include <iostream>
#include <vector>
#include <queue>
using namespace::std;
int n,k;
bool visited[100001];
int ftime[100001];
queue<int>q;


int bfs(int start, int target){
    q.push(start);
    visited[start]=true;
    ftime[start]=0;
    //visited[방문한 거리] = 몇번만에 방문했는지
   
    while (!q.empty()) {
        int v =q.front();
        q.pop();
        
        if(visited[target]) return ftime[target];


        //조건에 맞게 값주기
        if( v-1>=0 && visited[v-1]==0){
            visited[v-1]=true;
            ftime[v-1]=ftime[v]+1;
            q.push(v-1);
        }
        if( v*2<100001 && visited[v*2]==0){
            visited[v*2]=true;
            ftime[v*2]=ftime[v]+1;
            q.push(v*2);
        }
        if( v+1<100001 && visited[v+1] ==0){
            visited[v+1]=true;
            ftime[v+1]=ftime[v]+1;
            q.push(v+1);
        }
    }
    //반환할 이유 없으면 0으로 반환끝내기(뭐든 상관없긴 함)
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >>k;
    cout << bfs(n,k)<< "\n";
}
