#include <bits/stdc++.h>
using namespace std;
bool vis[10011];
bool p[10011];
int V = 10001;
vector <vector<int>> lista;
bool dfs (int atual)
{
	vis[atual] = true;
	p[atual] = true;
	for (int i=0;i<lista[atual].size();i++)
	{
		if (!vis[lista[atual][i]] && dfs(lista[atual][i]))	
			return true;
		else if (p[lista[atual][i]])
			return true;
	}	
	p[atual]=false;
	return false;
}
int main ()
{
	int n,a,t,x,y,V;
	cin >> t;
	while (t--)
	{
		memset(vis,false,sizeof vis);
		memset(p,false,sizeof p);
		
		cin >> V >> a;
		lista.resize(V);
		while (a--)
		{
			cin >> x >> y;
			lista[x-1].push_back(y-1);
		}
		bool ok = false;
		for (int i=0;i<V;i++)
		{
			if (dfs(i))
			{
				ok = true;
				break;
			}
		}		
		ok ? puts("SIM") : puts("NAO");
		lista.clear();
	}
}
