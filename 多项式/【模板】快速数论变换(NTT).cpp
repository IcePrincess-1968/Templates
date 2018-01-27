const LL MOD=998244353;
//MOD=119*2^23+1 费马素数
//可以处理长度在2^23以内的多项式，足够使用
const int G=3;
//998244353的原根G=3

//快速幂
LL quick_pow(LL x,LL y)
{
	x%=MOD;LL res=1;
	while (y)
	{
		if (y&1)
		{
			res=(res*x)%MOD;
			y--;
		}
		x=(x*x)%MOD;
		y>>=1;
	}
	return res;
}

void NTT(LL c[],int len,int fl)
{
	int i,j,k,clen,id=0;
	for (i=(len>>1),j=1;j<len;j++)
	{
		if (i<j) swap(c[i],c[j]);
		for (k=(len>>1);i&k;k>>=1) i^=k;
		i^=k;
	}
	for (clen=2;clen<=len;clen<<=1)
	{
		LL wn=quick_pow(G,fl==1?(MOD-1)/clen:(MOD-1)-(MOD-1)/clen);
	  	//这里容易写错！注意iDFT的时候所有的原根指数要取负！-(MOD-1)/clen不好算，利用原根的性质g^(MOD-1)=1,把指数转成正数
    	for (j=0;j<len;j+=clen)
		{
			LL w=1ll;
			for (k=j;k<j+(clen>>1);k++)
			{
				LL tmp1=c[k]%MOD,tmp2=((c[k+(clen>>1)]%MOD)*w)%MOD;
				c[k]=(tmp1+tmp2)%MOD;c[k+(clen>>1)]=((tmp1-tmp2)%MOD+MOD)%MOD;
				w=(w*wn)%MOD;
			}
		}
	}
	if (fl==-1)
	{
		LL inv=quick_pow(len,MOD-2);
		for (i=0;i<len;i++) c[i]=(c[i]%MOD*inv)%MOD;
	}
}	

void calc_NTT()
{
	int i,l=(1<<18);
	NTT(a,l,1);
	NTT(b,l,1);
	for (i=0;i<l;i++) a[i]=(a[i]*b[i])%MOD;
	NTT(a,l,-1);
}
