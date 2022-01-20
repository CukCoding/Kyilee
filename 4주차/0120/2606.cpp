//


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,d;

int dist[101][101];
bool check[101];
queue<int>q;

int bfs(int start){
    int cnt=0;
    q.push(start);
    check[start]=1;
   
    while (!q.empty()) {
        int v =q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if( check[i] ==0 && dist[v][i]==1){
                q.push(i);
                check[i]=1;
                cnt++;
            }
        }
    }
    return cnt;
    
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    cin >> d;
    for(int i=0; i<d; i++){
        int a,b;
        cin >> a >>b;
        dist[a][b]=1;
        dist[b][a]=1;
    }
    cout << bfs(1);
    
    //bfs 코드
    
}
