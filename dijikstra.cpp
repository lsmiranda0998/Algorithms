#include <bits/stdc++.h>
#define MAX 100105
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
vector<vector<pii>> g(MAX);
vector<vector<pii>> g2(MAX);
bool vis[MAX];
int V,a;
int x,y,w;
int dijikstra (int origem, int dest)
{
	int dist[MAX];
	for (int i=0;i<V;i++)
		dist[i] = inf;
	memset(vis,0,sizeof vis);
	priority_queue <pii,vector<pii> ,greater<pii>> pq;
	dist[origem] = 0;
	pq.push(pii(0,origem));
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (origem == dest) return w;
		
		if (!vis[cur])
		{
			vis[cur] = true;
			for (int i=0;i<g2[cur].size();i++)
			{
				int wadj = g2[cur][i].second;
				int adj = g2[cur][i].first;
				if ( wadj + dist[cur] < dist[adj])
				{
					dist[adj] = wadj+dist[cur];
					pq.push(pii(dist[adj],adj));
				}
			}
		}
	
	}
	return dist[dest];
	
}
int main ()
{

	
	cin >> V >> a;
	g.resize(V);
	g2.resize(V);
	while (a--)
	{
		cin >> x >> y >> w;
		x--,y--;
		g[x].push_back(pii(y,w));
		g[y].push_back(pii(x,w));
	}
	for (int i=0;i<V;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			int w = g[i][j].second;
			int adj = g[i][j].first;
			if (g[adj].size() > 0)
			{
				for (int k=0;k<g[adj].size();k++)
				{
					int w2 = g[adj][k].second;
					int adj2 = g[adj][k].first;
					g2[i].push_back(pii(adj2,w2+w));
				}
			}
		}
	}
	/*for (int i=0;i<g2.size();i++)
	{
		printf ("%d -> ",i);
		for (int j=0;j<g2[i].size();j++)
		{
			printf("%d, ",g2[i][j].second);
		}
		puts("");
	}*/
	printf("%d\n",dijikstra(0,V-1) == inf? -1 : dijikstra(0,V-1));
	
}
