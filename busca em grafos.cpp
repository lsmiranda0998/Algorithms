#include <bits/stdc++.h>
using namespace std;
vector<bool>vis(100,0);
vector<int> bfs (int atual,vector <vector<int>> g)
{
	queue <int> q;
	q.push(atual);
	vector<int>dist(g.size(),0);
	dist[atual] = 0;
	while (!q.empty())
	{
		int cur = q.front();
	
		q.pop();
		
		for (auto adj : g[cur])
		{
			if (!vis[adj])
			{
				vis[adj] = true;
				
				q.push(adj);
				dist[adj] = dist[cur]+1;
			}
		
		}
		//cout <<cur;
		
	}
	return dist;
}
void dfs(int atual,vector <vector<int>> g)
{
	vis[atual] = true;
	for (int i=0;i<g[atual].size();i++)
	{
		if (!vis[g[atual][i]])
		{
			//vis[g[atual][i]] = true;
			printf ("%d",g[atual][i]);
			dfs(g[atual][i],g);
			
		}
		
	}
}
int main ()
{
	int n,a,ini,t,x,y,cont,V;
	cin >> V >> a;
	vector <vector<int>> g(V);
	vector <int> dist;
		
	for (int i=0;i<a;i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	puts("-------------------------");
	/*for (int i=0;i<V;i++)
	{
		printf ("%d:",i);
		for (int j=0;j<g[i].size();j++)
		{
			cout << g[i][j] << " ";
		}
		puts("");
	}*/
	//dfs(0,g);
	dist = bfs(1,g);
	cout << dist[14];
	//cout << cont << '\n';
	
}
