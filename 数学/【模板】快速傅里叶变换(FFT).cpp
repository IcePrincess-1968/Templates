struct Complex
{
	double r,i;
	Complex() {}
	inline Complex(double curr,double curi)
	{
		r=curr;i=curi;
	}
	inline Complex operator + (Complex x)
	{
		return Complex(r+x.r,i+x.i);
	}
	inline Complex operator - (Complex x)
	{
		return Complex(r-x.r,i-x.i);
	}
	inline Complex operator * (Complex x)
	{
		return Complex(r*x.r-i*x.i,r*x.i+i*x.r);
	}
	inline Complex operator / (double x)
	{
		return Complex(r/x,i/x);
	}
}a[300048],b[300048];

int n,m;

//fl=1表示DFT,fl=-1表示iDFT
void FFT(Complex c[],int len,int fl)
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
		Complex wn=Complex(cos(pi*2.0*fl/clen),sin(pi*2.0*fl/clen));
    //wn是clen次单位复根
		for (j=0;j<len;j+=clen)
		{
			Complex w=Complex(1,0);
			for (k=j;k<j+(clen>>1);k++)
			{
				Complex tmp1=c[k],tmp2=c[k+(clen>>1)]*w;
				c[k]=tmp1+tmp2;c[k+(clen>>1)]=tmp1-tmp2;
				w=w*wn;
			}
		}
	}
	if (fl==-1)
		for (i=0;i<len;i++) c[i]=c[i]/len;
}	

void calc_FFT()
{
	int i,l=1;
	while (l<=n+m) l<<=1;
	FFT(a,l,1);
	FFT(b,l,1);
	for (i=0;i<l;i++) a[i]=a[i]*b[i];
	FFT(a,l,-1);
}
