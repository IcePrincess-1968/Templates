const LL MOD=998244353;
//MOD=119*2^23+1 费马素数
//可以处理长度在2^23以内的多项式，足够使用
const int G=3;
//998244353的原根G=3

int n,m,len;
LL a[300048],b[300048];

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

LL wn_pos[600048],wn_neg[600048];

inline void init_wn()
{
	for (register int clen=2;clen<=len;clen<<=1)
		wn_pos[clen]=quick_pow(G,(MOD-1)/clen),wn_neg[clen]=quick_pow(G,(MOD-1)-(MOD-1)/clen);
}

inline void NTT(LL c[],int fl)
{
	int i,j,k,clen;
	for (i=(len>>1),j=1;j<len;j++)
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
			LL w=1;
			for (k=j;k<j+(clen>>1);k++)
			{
				LL tmp1=c[k],tmp2=(c[k+(clen>>1)]*w)%MOD;
				c[k]=(tmp1+tmp2)%MOD;c[k+(clen>>1)]=((tmp1-tmp2)%MOD+MOD)%MOD;
				w=(w*wn)%MOD;
			}
		}
	}
	if (fl==-1)
	{
		LL inv=quick_pow(len,MOD-2);
		for (i=0;i<len;i++) c[i]=(c[i]*inv)%MOD;
	}
}

inline void calc_NTT()
{
	len=1;
	while (len<=n+m) len<<=1;
	init_wn();
	NTT(a,1);NTT(b,1);
	for (register int i=0;i<len;i++) a[i]*=b[i]%=MOD;
	NTT(a,-1);
}
