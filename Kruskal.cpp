#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define max 200001
struct tpAresta
{
	int x,y;
	int peso;	
};
int pai[max],peso[max];

bool cmp (tpAresta a, tpAresta b)
{
	return a.peso < b.peso;
}
int find (int x)
{
	if (pai[x] == x)
		return x;
	return pai[x] = find(pai[x]);
}
void merge (int x, int y)
{
	x = find (x);
	y = find (y);
	if (peso[x] < peso[y])
		pai[x] = y;
	if (peso[x] > peso [y])
		pai[y] = x;
	if (peso[x] == peso[y])
	{
		pai[x] = y;
		peso[y]++;
		//qtde[y]+=qtde[x];
	}
}
int main ()
{
	int n,m;
	while(cin >> n >> m && n or m)
	{
		int x,y,w;
		tpAresta mst[max];
		tpAresta arestas[max];
		int somat=0;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&w);
			//x--,y--;
			arestas[i].x = x;
			arestas[i].y = y;
			arestas[i].peso = w;
			somat+=w;
		}
		for (int i=0;i<n;i++)
			pai[i] = i;
		memset(peso,0,sizeof peso);
		sort(arestas,arestas+m,cmp);
		int tam=0;
		//memset(qtde,1,sizeof qtde);
		for (int i=0;i<m;i++)
		{
			if (find(arestas[i].x) != find (arestas[i].y))
			{
				merge(arestas[i].x,arestas[i].y);
				mst[tam++] = arestas[i];
			}
		}
		int soma=0;
		for (int i=0;i<tam;i++)
			soma+= mst[i].peso;
		printf ("%d\n",somat-soma);
	}
	
	
	
	
}



