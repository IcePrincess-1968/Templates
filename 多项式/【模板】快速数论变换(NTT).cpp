const LL MOD=998244353;
//MOD=119*2^23+1 费马素数
//可以处理长度在2^23以内的多项式，足够使用
const int G=3;
//998244353的原根G=3

LL a[300048],b[300048],wn_pos[300048],wn_neg[300048],inv;

LL quick_pow(LL x,LL y)
{
	LL res=1;x%=MOD;
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

void init_wn(int len)
{
	int clen;
	for (clen=2;clen<=len;clen<<=1)
	{
		wn_pos[clen]=quick_pow(G,(MOD-1)/clen);
		wn_neg[clen]=quick_pow(G,(MOD-1)-(MOD-1)/clen);
	}
}

void NTT(LL c[],int len,int fl)
{
	int i,j,k,clen;
	for (i=(len>>1),j=1;j<=len-1;j++)
	{
		if (i<j) swap(c[i],c[j]);
		for (k=(len>>1);i&k;k>>=1) i^=k;
		i^=k;
	}
	for (clen=2;clen<=len;clen<<=1)
	{
		LL wn=(fl==1?wn_pos[clen]:wn_neg[clen]);
		for (j=0;j<len;j+=clen)
		{
			LL w=1ll;
			for (k=j;k<j+(clen>>1);k++)
			{
				LL tmp1=c[k]%MOD,tmp2=(c[k+(clen>>1)]%MOD*w)%MOD;
				c[k]=(tmp1+tmp2)%MOD;c[k+(clen>>1)]=((tmp1-tmp2)%MOD+MOD)%MOD;
				w=(w*wn)%MOD;
			}
		}
	}
	if (fl==-1)
	{
		for (i=0;i<=len-1;i++) c[i]=(c[i]%MOD*inv)%MOD;
	}
}

void calc_NTT()
{
	int i,l=1;
	while (l<=n+m) l<<=1;
	init_wn(l);inv=quick_pow(l,MOD-2);
	NTT(a,l,1);
	NTT(b,l,1);
	for (i=0;i<=l-1;i++) a[i]=(a[i]*b[i])%MOD;
	NTT(a,l,-1);
}