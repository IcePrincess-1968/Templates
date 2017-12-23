void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	int i,j;
	for (i=2;i<=n;i++)
	{
		if (isprime[i]) prime[++tot]=i;
		for (j=1;j<=tot;j++)
		{
			LL mul=prime[j];mul*=i;if (mul>n) break;
			isprime[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
}
