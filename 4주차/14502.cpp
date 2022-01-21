
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
queue <pair<int, int>> q;
int n,m;
int field[10][10];
int xy[4][2] ={{1,0},{0,-1},{-1,0},{0,1}};
int safezone=-1;

int findzone(){
    int ii= q.front().first;
    int jj= q.front().second;
    q.pop();
    
    while (!q.empty()) {
        for(int i=0; i<4; i++)
        {
            int next_i =ii+xy[i][0];
            int next_j =jj+xy[i][1];
            //y좌표와 y배열 방향이 다르기 때문
            
            if(field[next_i][next_j]==0 && 0<=next_i && next_i<n && 0<=next_j && next_j<m)
            {
                field[next_i][next_j]=2;
                q.push(make_pair(next_i,next_j));
            }
        }
    }
    
    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if (field[n][m] ==0)cnt++;
    
    
    return cnt;
}


void make_wall(int wall){
    
    if(wall ==3)    safezone=max(findzone(),safezone);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if (field[i][j] ==0)
            {
                field[i][j] =1;
                make_wall(wall+1);
                field[i][j] =0;
            }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>> n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> field[i][j];
            if(field[i][j]==2) q.push(make_pair( i,j));
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
             if (field[i][j] == 0)
             {

             }

    make_wall(0);
    cout << safezone << "\n";
    
}
