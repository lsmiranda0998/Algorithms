#include <bits/stdc++.h>
using namespace std;
void solve (vector<vector<int>> &S, vector<int> &A, int cur,vector<int> C,bool vis[],int k)
{
    vis[cur] = true;	
    C.push_back(A[cur]);
    if (C.size() == k)
        S.push_back(C);		
    else
    {
        for (int i=cur;i<A.size();i++)
        {
        	if (!vis[i])
        		solve(S,A,i,C,vis,k);	   	
        }
    }
    vis[cur] = false;
}
int main ()
{ 
	vector<int> A = {1,2,3,4};
	bool vis[A.size()];
	memset(vis,false,sizeof vis);
	vector<vector<int>> S;
	for (int i=0;i<A.size();i++)
		solve (S,A,i,{},vis,2);
	for (int i=0;i<S.size();i++)
	{
		for (int j=0;j<S[i].size();j++)
		{
			cout << S[i][j] << " ";
		}	
		puts("");
	}
}
