bool isprime[20000048];
int prime[20000048],tot=0;
int phi[20000048];
int MOD;
int n;

void sieve_phi()
{
	memset(isprime,true,sizeof(isprime);
	int i,j;
	for (i=2;i<=n;i++)
	{
		if (isprime[i]) prime[++tot]=i,phi[i]=i-1;
		for (j=1;j<=tot && 1ll*prime[j]*i<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if (i%prime[j]==0) phi[i*prime[j]]=(phi[i]*prime[j])%MOD; else phi[i*prime[j]]=(phi[i]*(prime[j]-1))%MOD;
			if (i%prime[j]==0) break;
		}
	}
}
