namespace SA
{
	int cnt[MAXN+48],fir[MAXN+48],sec[MAXN+48],sa[MAXN+48],tmp[MAXN+48];
	int rnk[MAXN+48],lcp[MAXN+48];
	inline bool compare_sa(int x,int y,int k)
	{
		if (fir[x]!=fir[y]) return fir[x]<fir[y];
		int tmp1=(x+k<=n?fir[x+k]:-1),tmp2=(y+k<=n?fir[y+k]:-1);
		return tmp1<tmp2;
	}
	inline void construct_sa(char s[])
	{
		int maxind='z';memset(cnt+1,0,maxind<<2);
		for (register int i=1;i<=n;i++) cnt[s[i]]++;
		for (register int i=1;i<=maxind;i++) cnt[i]+=cnt[i-1];
		for (register int i=n;i>=1;i--) sa[cnt[s[i]]--]=i;
		fir[sa[1]]=1;for (register int i=2;i<=n;i++) fir[sa[i]]=fir[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
		for (register int len=1;len<=n;len<<=1)
		{
			int tot=0;
			for (register int i=n-len+1;i<=n;i++) sec[++tot]=i;
			for (register int i=1;i<=n;i++) if (sa[i]>len) sec[++tot]=sa[i]-len;
			memset(cnt+1,0,maxind<<2);
			for (register int i=1;i<=n;i++) cnt[fir[sec[i]]]++;
			for (register int i=1;i<=maxind;i++) cnt[i]+=cnt[i-1];
			for (register int i=n;i>=1;i--) sa[cnt[fir[sec[i]]]--]=sec[i];
			tmp[sa[1]]=tot=1;
			for (register int i=2;i<=n;i++) tmp[sa[i]]=tmp[sa[i-1]]+compare_sa(sa[i-1],sa[i],len);
			memcpy(fir+1,tmp+1,n<<2);
			maxind=fir[sa[n]];if (maxind>=n) break;
		}
	}
	inline void construct_lcp()
	{
		int h=0;
		for (register int i=1;i<=n;i++) rnk[sa[i]]=i;
		for (register int i=1;i<=n;i++)
		{
			int j=sa[rnk[i]-1];
			if (h) h--;
			while (i+h<=n && j+h<=n && s[i+h]==s[j+h]) h++;
			lcp[rnk[i]-1]=h;
		}
	}
}
