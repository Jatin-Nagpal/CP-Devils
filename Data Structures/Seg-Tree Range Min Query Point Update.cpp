#include <bits/stdc++.h>
using namespace std;
#define f(i,x,n) for(int i=x;i<n;i++)

// Range Minimum Query and Point Update value
#define MOD 100000007 //Check this first
#define N 200000 //Check the limits dummy
int bit[4*N+10];
int func(int a,int b)
{
	return min(a,b); //Check if u don't wanna find min
}
void init()
{
	f(i,0,4*N+5)
		bit[i]=MOD; //Check this carefully
}
int upd(int i,int j, int index,int val,int node)
{
	if(i==j&&index!=i)
		return bit[node];
	if(i==j)
		return bit[node]=val;
	else if(i<=index&&j>=index)
		return bit[node]=func(upd(i,(i+j)/2,index,val,2*node), upd((i+j)/2+1,j,index,val,2*node+1) );
	return bit[node];
}
int qry(int i,int j,int l,int r,int node)
{
	if(i==j)
	{
		if(l<=i&&r>=j)
			return bit[node];
		else
			return MOD;
	}
	else if(l>j||r<i)
		return MOD;
	else if(l<=i&&r>=j)
		return bit[node];
	int mid=(i+j)/2;
	return func(qry(i,mid,l,r,2*node),qry(mid+1,j,l,r,2*node+1));
}