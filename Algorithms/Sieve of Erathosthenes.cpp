// 0 if prime, else shortest factor of number
int prime[N];
void sieve(int n) {
	prime[0]=prime[1]=1; //To be taken care of
	for(int i=2;i*i<=n;i++)
		if(prime[i]==0)
			for(int j=i*i;j<=n;j+=i)
				if(prime[j]==0)
					prime[j]=i;
}