const int MAXN=400;

int n,e,nl,nr;

int linkx[MAXN+48],linky[MAXN+48],slack[MAXN+48],pre[MAXN+48];
bool vx[MAXN+48],vy[MAXN+48];int lx[MAXN+48],ly[MAXN+48];
int ga[MAXN+48][MAXN+48];

inline void find_route(int &u)
{
	for (;u;swap(u,linkx[pre[u]]))
		linky[u]=pre[u];
}

int q[MAXN+48],head,tail;
inline void bfs(int u)
{
	head=tail=1;q[1]=u;vx[u]=true;int t;
	for (;;)
	{
		while (head<=tail)
		{
			u=q[head++];
			for (register int v=1;v<=n;v++)
			{
				if (vy[v] || (t=lx[u]+ly[v]-ga[u][v])>slack[v]) continue;
				pre[v]=u;
				if (!t)
				{
					if (!linky[v]) {find_route(v);return;}
					vy[v]=true;vx[linky[v]]=true;q[++tail]=linky[v];
				}
				else slack[v]=t;
			}
		}
		int d=INF;
		for (register int v=1;v<=n;v++) if (!vy[v] && slack[v]<d) d=slack[v],u=v;
		for (register int i=1;i<=n;i++)
		{
			if (vx[i]) lx[i]-=d;
			if (vy[i]) ly[i]+=d; else slack[i]-=d;
		}
		if (!linky[u]) {find_route(u);return;}
		vy[u]=true;vx[linky[u]]=true;q[++tail]=linky[u];
	}
}

inline void KM()
{
	memset(linkx,0,sizeof(linkx));memset(linky,0,sizeof(linky));
	for (register int i=1;i<=n;i++) lx[i]=-INF,ly[i]=0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			lx[i]=max(lx[i],ga[i][j]);
	for(register int i=1;i<=n;i++)
	{
		for (register int j=1;j<=n;j++) vx[j]=vy[j]=false,slack[j]=INF;
		bfs(i);
	}
}

