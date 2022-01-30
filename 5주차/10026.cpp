
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int n;

int normal, weak;
string s[101];
bool Nvisit[101][101];
bool Wvisit[101][101];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


void bfs(int a, int b){
    Nvisit[a][b] =1;
    queue<pair<int, int>>q;
    q.push({a,b});
    char color = s[a][b];
    normal++;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int na=cur.first +dx[i];
            int nb=cur.second+dy[i];
            if(na<0 || nb<0 || na>=n || nb>=n) continue;
            if(Nvisit[na][nb]==1 || s[na][nb]!=color) continue;
            Nvisit[na][nb]=1;
            q.push({na,nb});
        }
    }
    
    if( Wvisit[a][b] == false)
    {
        Wvisit[a][b] =1;
        queue<pair<int, int>>q;
        q.push({a,b});
        weak++;
        
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            for(int i=0; i<4; i++)
            {
                int na=cur.first +dx[i];
                int nb=cur.second+dy[i];
                if(na<0 || nb<0 || na>=n || nb>=n || Wvisit[na][nb]==1) continue;
                if(color == 'B' && s[na][nb]==color)
                {
                    Wvisit[na][nb]=1;
                    q.push({na,nb});
                }
                else
                {
                    if( (color=='R' || color=='G') &&( s[na][nb]=='R' || s[na][nb]=='G'))
                    {
                        Wvisit[na][nb]=1;
                        q.push({na,nb});
                    }
                }
            }
        }
    }


}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(Nvisit[i][j]==1) continue;
            bfs(i,j);
        }
    }
    
    
    
    
    cout << normal << " " << weak;
    
    
}


