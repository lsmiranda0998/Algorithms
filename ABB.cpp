#include <bits/stdc++.h>
using namespace std;
struct tree
{	
	int info;
	struct tree *esq;
	struct tree *dir;
};
typedef struct tree Tree;

bool flag = false;

Tree * achaPai(Tree *r, int v)
{	
	if(r == NULL)
		return NULL;
	else
		if(v <= r->info)
		{
			if(r->esq == NULL)
				return r;
			else
				return achaPai(r->esq, v);
		}
		else
		{
			if(r->dir == NULL)
				return r;
			else
				return achaPai(r->dir, v);
		}
		
}

void preOrdem(Tree* raiz)
{
	
	if(raiz != NULL)
	{
		printf(" %d", raiz->info);
		preOrdem(raiz->esq) ;
		preOrdem(raiz->dir) ;
	}
}

void emOrdem(Tree* raiz)
{
	
	if(raiz != NULL)
	{
	
		emOrdem( raiz->esq) ;
		printf(" %d", raiz->info);
		emOrdem(raiz->dir);
	}
}



void posOrdem(Tree* raiz)
{
	if(raiz != NULL)
	{
	
		posOrdem(raiz->esq) ;
		posOrdem( raiz->dir) ;
		printf(" %d", raiz->info);
	
	}
}
int main()
{	

	Tree *raiz, *pai, *no;
	int n;
	scanf("%d",&n);
	for (int j=0;j<n;j++)
	{
		
		raiz = NULL;
		int k;
		scanf("%d",&k);
		for (int i=0;i<k;i++)	
		{
			int num;
			scanf ("%d",&num);
			no = (Tree*) malloc(sizeof(Tree));
			no->info = num;
			no->esq  = NULL;
			no->dir  = NULL;
			pai = achaPai (raiz,num);
			if (pai == NULL)
				raiz = no;
			else
			{
				if (num <= pai->info)
					pai->esq = no;
				else
					pai->dir = no;
			}
		}
		printf ("Case %d:\n",j+1);
		printf("Pre.:");
		preOrdem(raiz);
		puts("");
		printf("In..:");
		emOrdem(raiz);
		puts("");
		printf("Post:");
		posOrdem(raiz);
		puts("");
		puts("");
	}

	return 0;
}

