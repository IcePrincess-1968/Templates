void init()
{
	int i;
	inv[0]=inv[1]=1;
	for (i=2;i<=p-1;i++)
		inv[i]=(p-((p/i)*inv[p%i])%p)%p;
	finv[0]=finv[1]=1;
	for (i=2;i<=p-1;i++) finv[i]=(finv[i-1]*inv[i])%p;
	f[0]=f[1]=1;
	for (i=2;i<=200000;i++) f[i]=(f[i-1]*i)%p;
}

//C(n,m)%p=(C(n%p,m%p)*C(n/p,m/p))%p
LL Lucas(int n,int m)
{
	int nn=n%p,mm=m%p;
	if (nn<mm) return (LL)0;
	if (mm==0) return (LL)1;
	LL res=f[nn];
	res=(res*finv[mm])%p;
	res=(res*finv[nn-mm])%p;
	res=(res*Lucas(n/p,m/p))%p;
	return res;
}
