#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)

//Double Hash with Size of the String
#define SZ 2005 // Check the Limits Dummy
int Mi[2]={758620695,838709685}; // Mod-inverse of 29 and 31 respectively
int M[2]={1000000007,1000000009}; // Modulo values
int D[2]={29,31}; //Best values for 26 ASCII set
int po[SZ][2]; // Power values
int poi[SZ][2]; // Mod-Inv Power Values
void pre(int n)
{
	po[0][0]=po[0][1]=poi[0][0]=poi[0][1]=1;
	f(i,1,n+1)
	{
		f(j,0,2)
		{
			po[i][j]=(po[i-1][j]*D[j])%M[j];
			poi[i][j]=(poi[i-1][j]*Mi[j])%M[j];
		}
	}
}

pair <int,int> addLeft(pair <int,int> &val,char ch)
{
	int sz=val.ff/M[0];
	val.ff=(val.ff%M[0]*D[0]+(ch-'a'+1))%M[0];
	val.ss=(val.ss*D[1]+(ch-'a'+1))%M[1];
	val.ff+=(sz+1)*M[0];
	return val;
}
pair <int,int> addRight(pair <int,int> &val,char ch)
{
	int sz=val.ff/M[0];
	val.ff=(val.ff%M[0]+(ch-'a'+1)*po[sz][0])%M[0];
	val.ss=(val.ss+(ch-'a'+1)*po[sz][1])%M[1];
	val.ff=val.ff+(sz+1)*M[0];
	return val;
}
pair <int,int> remLeft(pair <int,int> &val,char ch)
{
	int sz=val.ff/M[0];
	val.ff=(( (val.ff%M[0]-(ch-'a'+1)) *Mi[0])%M[0]+M[0])%M[0];
	val.ss=(( (val.ss-(ch-'a'+1)) *Mi[1])%M[1]+M[1])%M[1];
	val.ff+=(sz-1)*M[0];
	return val;
}
pair <int,int> remRight(pair <int,int> &val,char ch)
{
	int sz=val.ff/M[0];
	val.ff=((val.ff%M[0]-po[sz-1][0]*(ch-'a'+1))%M[0]+M[0])%M[0];
	val.ss=((val.ss-po[sz-1][1]*(ch-'a'+1))%M[1]+M[1])%M[1];
	val.ff+=(sz-1)*M[0];
	return val;
}

// Proof of Correctness:-
// https://codeforces.com/contest/113/submission/62671933