//1753 최단경로
#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> pii;

int V, E, start;
vector<pii> edge[20001];
vector<int> dist; //최단경로값

void dijkstra()
{

    dist.resize(V + 1, INF);
    dist[start] = 0;

    priority_queue<pii> pq;
    pq.push({0, start});
    // 가중치, 정점
    //가중치 순서로 정렬되야해서 먼저옴

    while (!pq.empty())
    {
        int cost = -pq.top().first; //양수로 꺼냄
        int node = pq.top().second;
        pq.pop();

        for (int i = 0; i < edge[node].size(); i++)
        {

            int nextnode = edge[node][i].first;
            int nextcost = edge[node][i].second;

            if (dist[nextnode] > dist[node] + nextcost)
            { //현재 최단경로값과 더한걸 비교
                dist[nextnode] = dist[node] + nextcost;
                pq.push({-dist[nextnode], nextnode}); //거리정보를 음수로 삽입
            }
        }
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> start; // cin은 줄바꿈 신경 안쓰나봄

    for (int i = 0; i < E; i++)
    {
        int u, v, w; //u->v로 가는 가중치 w인 간선
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    dijkstra();

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
            cout << dist[i] << "\n";
    }
}
