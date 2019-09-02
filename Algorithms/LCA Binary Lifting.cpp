#include <bits/stdc++.h>
using namespace std;
#define f(i,x,n) for(int i=x;i<n;i++)

#define N 200005 //Check the limits dummy
int n,timer;
const int l=ceil(log2(N));
int tin[N],tout[N];
vector <int> gp[N];
vector <int> up[N];
int parent[N];
void dfs(int i,int par)
{
	tin[i]=++timer;
	parent[i]=par;
	for(int j: gp[i])
		if(j!=par)
			dfs(j,i);
	tout[i]=timer;
}
int check(int par,int i)
{
	return tin[par]<=tin[i] && tout[par]>=tout[i];
}
int LCA(int u,int v)
{
	if(check(u,v))
		return u;
	if(check(v,u))
		return v;
	for(int i=l;i>=0;i--)
		if(!check(up[u][i],v))
			u=up[u][i];
	return up[u][0];
}
void init(int root)
{
	dfs(root,root);
	f(i,1,n+1)
		up[i].push_back(parent[i]);
	f(j,1,l+1)
		f(i,1,n+1)
			up[i].push_back(up[up[i][j-1]][j-1]);
}
