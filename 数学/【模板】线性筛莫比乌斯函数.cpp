bool isprime[20000048];
int prime[20000048],tot=0;
int mu[20000048];

void sieve_mu()
{
	int i;
	memset(isprime,true,sizeof(isprime));
	for (i=2;i<=n;i++)
	{
		if (isprime[i]) prime[++tot]=i,mu[i]=-1;
		for (j=1;j<=tot && prime[j]*i<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if (i%prime[j]==0) mu[i*prime[j]]=0; else mu[i*prime[j]]=-mu[i];
			if (i%prime[j]==0) break;
		}
	}
}
