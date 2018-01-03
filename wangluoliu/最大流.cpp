int t,tot,head[1048],to[400048],nxt[400048],f[400048];
inline void addedge(int s,int t,int cap)
{
	to[++tot]=t;nxt[tot]=head[s];head[s]=tot;f[tot]=cap;
	to[++tot]=s;nxt[tot]=head[t];head[t]=tot;f[tot]=0;
}

int depth[1048];queue<int> q;
bool bfs()
{
	int i,x,y;
	for (i=0;i<=t;i++) depth[i]=-1;
	depth[0]=0;q.push(0);
	while (!q.empty())
	{
		x=q.front();q.pop();
		for (i=head[x];i;i=nxt[i])
		{
			y=to[i];
			if (f[i] && depth[y]==-1)
			{
				depth[y]=depth[x]+1;
				q.push(y);
			}
		}
	}
	if (depth[t]==-1) return false; else return true;
}

int dfs(int x,int maxf)
{
	if (x==t) return maxf;
	int i,y,now,ans=0,minf;
	for (i=head[x];i;i=nxt[i])
	{
		y=to[i];
		if (f[i] && depth[y]==depth[x]+1)
		{
			minf=min(f[i],maxf-ans);
			now=dfs(y,minf);
			f[i]-=now;
			f[i^1]+=now;
			ans+=now;
		}
	}
	return ans;
}

int main ()
{
    int ans=0;
    while (bfs()) ans+=dfs(0,2e9);
}
