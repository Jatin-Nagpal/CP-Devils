#define TP int
#define MAXN 1000000
#define K 25
int lg[MAXN+1];
TP st[MAXN][K+1];
TP func(TP a,TP b)
{
	return a+b; //Just Edit this function
}
int init(TP a[],int n)
{
	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		lg[i] = lg[i/2] + 1;
	f(i,0,n)
		st[i][0]=a[i];
	f(j,1,lg[n]+1)
		for(int i=0;i+(1<<j)<=n;i++)
			st[i][j]=func(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	return 0;
}
int com(TP a[],int n,int L,int R)
{
	TP val=0;
	for(int j=K;j>=0;j--)
	{
		if((1<<j)<=R-L+1)
		{
			val=func(val,st[L][j]);
			L+=1<<j;
		}
	}
	return val;
}