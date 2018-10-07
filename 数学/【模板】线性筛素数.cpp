void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	int i,j;
	for (i=2;i<=n;i++)
	{
		if (isprime[i]) prime[++tot]=i;
		for (j=1;j<=tot && 1ll*i*prime[j]<=n;j++)
		{
			isprime[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
}
