int n,e,s,t;

int head[200048],nxt[2000548],to[200048],f[200048],w[200048],tot=1;
inline void addedge(int s,int t,int l,int cost)
{
	to[++tot]=t;nxt[tot]=head[s];head[s]=tot;f[tot]=l;w[tot]=cost;
	to[++tot]=s;nxt[tot]=head[t];head[t]=tot;f[tot]=0;w[tot]=-cost;
}

int prevv[200048],preve[200048];
int h[200048];

priority_queue<Pair> q;int dist[200048];
bool dijkstra()
{
	int i,x,y,dd;
	for (i=1;i<=n;i++) dist[i]=INF;
	dist[s]=0;q.push(mp(0,s));
	while (!q.empty())
	{
		x=q.top().y;dd=-q.top().x;q.pop();
		if (dd>dist[x]) continue;
		for (i=head[x];i;i=nxt[i])
		{
			y=to[i];
			if (f[i] && dist[x]+w[i]+h[x]-h[y]<dist[y])
			{
				dist[y]=dist[x]+w[i]+h[x]-h[y];
				prevv[y]=x;preve[y]=i;
				q.push(mp(-dist[y],y));
			}
		}
	}
	if (dist[t]>=INF) return false; else return true;
}

Pair min_cost_flow()
{
	int i,u,res,minf;
	for (i=1;i<=n;i++) h[i]+=dist[i];
	minf=INF;
	for (u=t;u!=s;u=prevv[u]) minf=min(minf,f[preve[u]]);
	res=minf*h[t];
	for (u=t;u!=s;u=prevv[u])
	{
		f[preve[u]]-=minf;
		f[preve[u]^1]+=minf;
	}
	return mp(minf,res);
}

int main ()
{
	while (dijkstra())
	{
		Pair res=min_cost_flow();
		ans.x+=res.x;ans.y+=res.y;
	}
	printf("%d %d\n",ans.x,ans.y);
}
