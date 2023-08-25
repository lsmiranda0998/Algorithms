#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll MAX = 10e5+5;
int n;
ll tree[MAX*4];
ll lazy[MAX*4];
void update(int no,int l,int r,int i,int j,ll v)
{
	int mid = (l+r)/2;
	int nol = 2*no;
	int nor= 2*no+1;
	if (lazy[no])
	{
		tree[no] += lazy[no] * (r-l+1); //somo o valor de lazy para o intervalo [l,r]
		if (i!=j) // possui decendentes
		{
			lazy[nol]+=lazy[no];
			lazy[nor]+=lazy[no];
		}
		lazy[no] = 0;
	}
	if (l>r or l>j or i>r) // n pertence a esse no
		return;
	if (i<=l and r<=j) // operação cobre o intervalo inteiro
	{
		tree[no] += v*(r-l+1);
		if (i!=j) // possui decendentes, atualiza cada um ao invés da recursão
		{
			lazy[nol]+= v;
			lazy[nor]+= v;
		}
	}
	else
	{
		update(nol,l,mid,i,j,v);
		update(nor,mid+1,r,i,j,v);
		tree[no] = tree[nol] + tree[nor];
	}
}
ll get (int no,int l,int r,int i,int j)
{
	int mid = (l+r)/2;
	int nol = 2*no;
	int nor= 2*no+1;
	if (lazy[no])
	{
		tree[no] += lazy[no] * (r-l+1);
		if (i!=j)
		{
			tree[nol] += lazy[no];
			tree[nor] += lazy[no];
		}
		lazy[no]=0;
	}
	if (l>r or l>j or i>r) // esta disjunto, ou seja fora de l,r
		return 0;
	if (i<=l && r<=j) // contido dentro do intervalo
		return tree[no];
	return get(nol,l,mid,i,j) +	get(nor,mid+1,r,i,j);
}
int main ()
{	
	int t;
	scanf ("%d",&t);
	int c;
	while (t--)
	{
		int op,p,q;
		ll v;
		scanf ("%d%d",&n,&c);
		memset(tree,0,sizeof tree);
		memset(lazy,0,sizeof lazy);
		while (c--)
		{
			scanf("%d%d%d",&op,&p,&q);
			if (op == 0)
			{
				scanf("%lld",&v);
				update(1,0,n-1,p-1,q-1,v);
			}
			else
				printf("%lld\n",get(1,0,n-1,p-1,q-1));
		}
	}
}
