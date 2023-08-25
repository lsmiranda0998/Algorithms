#include <bits/stdc++.h>
#define MAX 10
#define inf 0x3f3f3f3f
using namespace std;

struct Trie
{
	unordered_map<char,Trie*> node;
	bool terminal = false;
};
int main()
{
	int n;
	Trie *raiz = new Trie();
	cin >> n;
	int cont = 0;
	while (n--)
	{
		string str;
		cin >> str;
		bool novo = true;
		Trie *atual = raiz;
		for (auto ch : str)
		{
			int index = ch-'a';
			if (novo)
				cont++;
			Trie *prox = atual->node[index];
			if (prox == NULL)
			{
				prox = new Trie();
				atual->node[index] = prox;
				novo = false;
			}
			atual = prox;	
			
		}
		atual->terminal = true;
	}
	printf ("Letras economizadas:%d\n",cont);
	
	
	
}
