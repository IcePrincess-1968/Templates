int head[200048],to[400048],nxt[400048],f[400048],cost[400048],tot=1;
inline void addedge(int s,int t,int cap,int c)
{
	to[++tot]=t;nxt[tot]=head[s];head[s]=tot;f[tot]=cap;cost[tot]=c;
	to[++tot]=s;nxt[tot]=head[t];head[t]=tot;f[tot]=0;cost[tot]=-c;
}

int n,e,S,T;
int D[200048];bool visited[10048];
int maxflow,mincost;

inline int aug(int cur,int maxf)
{
	visited[cur]=true;
	if (cur==T) {maxflow+=maxf;mincost+=(-D[S])*maxf;return maxf;}
	int i,y,now,minf,ans=0;
	for (i=head[cur];i;i=nxt[i])
	{
		y=to[i];
		if (f[i] && !visited[y] && D[cur]+cost[i]-D[y]==0)
		{
			minf=min(maxf-ans,f[i]);
			now=aug(y,minf);
			f[i]-=now;f[i^1]+=now;ans+=now;
		}
		if (ans>=maxf) return ans;
	}
	return ans;
}

inline bool relabel()
{
	int d=INF,cur,i,y;
	for (cur=1;cur<=n;cur++)
		if (visited[cur])
			for (i=head[cur];i;i=nxt[i])
			{
				y=to[i];
				if (f[i] && !visited[y]) d=min(d,D[cur]+cost[i]-D[y]);
			}
	if (d>=INF) return false;
	for (cur=1;cur<=n;cur++) if (visited[cur]) D[cur]-=d;
	return true;
}

int main ()
{
	int i,x,y,cap,cc;
	n=getint();e=getint();S=getint();T=getint();
	for (i=1;i<=e;i++)
	{
		x=getint();y=getint();cap=getint();cc=getint();
		addedge(x,y,cap,cc);
	}
	maxflow=mincost=0;
	do
		do
			memset(visited,false,sizeof(visited));
		while (aug(S,INF));
	while (relabel());
	printf("%d %d\n",maxflow,mincost);
	return 0;
}
