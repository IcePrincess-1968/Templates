const int MAXN=400;

int n,nl,nr;
int ga[MAXN+48][MAXN+48];
bool visitedx[MAXN+48],visitedy[MAXN+48];int linkx[MAXN+48],linky[MAXN+48];
int wx[MAXN+48],wy[MAXN+48],slack[MAXN+48];

inline bool find(int cur)
{
	visitedx[cur]=true;int t;
	for (register int i=1;i<=n;i++)
		if (!visitedy[i] && (t=wx[cur]+wy[i]-ga[cur][i])<=slack[i])
			if (!t)
			{
				visitedy[i]=true;
				if (!linky[i] || find(linky[i]))
				{
					linky[i]=cur;linkx[cur]=i;
					return true;
				}
			}
			else slack[i]=min(slack[i],t);
	return false;
}

inline void update()
{
	int d=INF;
	for (register int i=1;i<=n;i++) if (!visitedy[i]) d=min(d,slack[i]);
	for (register int i=1;i<=n;i++) if (visitedx[i]) wx[i]-=d;
	for (register int i=1;i<=n;i++) if (visitedy[i]) wy[i]+=d; else slack[i]-=d;
}

inline void KM()
{
	memset(linkx,0,sizeof(linkx));
	memset(linky,0,sizeof(linky));
	for (register int i=1;i<=n;i++) wx[i]=-INF;
	memset(wy,0,sizeof(wy));
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			wx[i]=max(wx[i],ga[i][j]);
	for (register int i=1;i<=n;i++)
	{
		for (register int j=1;j<=n;j++) slack[j]=INF;
		for (;;)
		{
			memset(visitedx,false,sizeof(visitedx));
			memset(visitedy,false,sizeof(visitedy));
			if (find(i)) break; else update();
		}
	}
}
