#include <bits/stdc++.h>
using namespace std;
bool vis[10011];
int V = 10001;
vector <vector<int>> lista(V);
bool dfs (int atual,int pai)
{
	vis[atual] = true;
	for (int i=0;i<lista[atual].size();i++)
	{
		if (!vis[lista[atual][i]])
		{		
			if (dfs(lista[atual][i],atual))
				return true;
		}
		else if (pai != lista[atual][i])
			return true;
	}

	return false;
}
int main ()
{
	int n,a,t,x,y,V;
	cin >> t;
	while (t--)
	{
		memset(vis,0,sizeof vis);
		cin >> V >> a;
		while (a--)
		{
			cin >> x >> y;
			lista[x].push_back(y);
			lista[y].push_back(x);
		}
		bool ok = false;
		for (int i=0;i<V;i++)
		{
			if (!vis[i])
			{
				if (dfs(i,-1))
				{
					ok = true;
					break;
				}	
			}
				
		}
			
					
		ok ? puts("SIM") : puts("NAO");
		
	}
}
