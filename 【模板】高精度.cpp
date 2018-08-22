struct Bigint
{
	#define bucket 10000000
	int len;LL b[3048];
	inline void clear() {memset(b,0,sizeof(b));len=0;}
	inline void Set(int x)
	{
		len=0;
		if (x==0) {len=1;return;}
		while (x) b[++len]=x%bucket,x/=bucket;
	}
	inline Bigint operator + (Bigint other)
	{
		Bigint res;res.clear();
		for (register int i=1;i<=max(len,other.len);i++)
		{
			res.b[i]+=b[i]+other.b[i];
			res.b[i+1]+=res.b[i]/bucket;
			res.b[i]%=bucket;
		}
		res.len=max(len,other.len);
		if (res.b[res.len+1]) res.len++;
		return res;
	}
	inline Bigint operator * (Bigint other)
	{
		Bigint res;res.clear();
		for (register int i=1;i<=len;i++)
			for (register int j=1;j<=other.len;j++)
				res.b[i+j-1]+=b[i]*other.b[j];
		for (register int i=1;i<=len+other.len-1;i++)
			res.b[i+1]+=res.b[i]/bucket,res.b[i]%=bucket;
		res.len=len+other.len-1;
		if (res.b[res.len+1]) res.len++;
		return res;
	}
	inline int getw(int x)
	{
		if (!x) return 1;
		int res=0;
		while (x) res++,x/=10;
		return res;
	}
	inline void print()
	{
		io.Print(b[len]);
		for (register int i=len-1;i>=1;i--)
		{
			int w=getw(b[i]);
			for (register int j=1;j<=7-w;j++) io.Writechar('0');
			io.Print(b[i]);
		}
		io.Writechar('\n');
	}
};
