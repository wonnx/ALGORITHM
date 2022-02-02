#include<iostream>
#include<queue>
using namespace std;
#define MAXN 501

int n, m, s, d, a, b, c;
int adj[MAXN][MAXN], dist[MAXN], visit[MAXN];

void dijkstra() 
{
    fill(dist, dist + MAXN, -1);
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,s });
    while (pq.size()) {
        auto now = pq.top(); pq.pop();
        if (dist[now.second] != -1)continue;
        dist[now.second] = -now.first;
        for (int i = 0; i < n; i++) {
            if (adj[now.second][i] == -1)continue;
            if (dist[i] != -1)continue;
            pq.push({ now.first - adj[now.second][i],i });
        }
    }
}

void eraseEdge() 
{
    queue<int> qu; qu.push(d);
    fill(visit, visit + MAXN, 0);
    while (qu.size()) {
        auto now = qu.front(); qu.pop();
        if (visit[now])continue;
        else visit[now]++;
        for (int i = 0; i < n; i++) {
            if (dist[now] == dist[i] + adj[i][now] && adj[i][now] != -1) {
                adj[i][now] = -1;
                qu.push(i);
            }
        }
    }
}

int main() 
{
    while (true) 
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> d;
        memset(adj, -1, sizeof(adj));
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a][b] = c;
        }
        dijkstra();
        eraseEdge();
        dijkstra();
        cout << dist[d] << endl;
    }
}