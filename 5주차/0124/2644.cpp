//
//  main.cpp
//  2644
//
//  Created by 뜽효니 on 2022/01/27.
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int chon[105];
vector<int> con[105];
queue <int> q;
int me,you;

void bfs(){
    q.push(me);

    while (!q.empty()){
        int now =q.front();
        q.pop();
        
        if(now == you ) {
            printf("%d",chon[you]);
            return;
        }
        
        for (int i=0; i<con[now].size(); i++){
            
            int next = con[now][i];
            
            if (!chon[next]){
                q.push(next);
                chon[next] = chon[now]+1;

            }
        }
    }
    printf("%d",-1);
    return ;
}

int main(){
    int n,m;
    cin >> n;
    scanf("%d %d", &me, &you);
    cin >> m;
    for( int i=0; i<m; i++){
        int p,c;
        scanf("%d %d", &p, &c);
        con[p].push_back(c);
        con[c].push_back(p);
    }
    bfs();
    printf("\n");
    
}
