int sz[100048];
bool taboo[100048];
int Cnt[100048];

inline void dfs(int cur,int father)
{
	int i,y;sz[cur]=1;
	for (i=head[cur];i;i=nxt[i])
	{
		y=to[i];
		if (y!=father && !taboo[y])
		{
			dfs(y,cur);
			sz[cur]+=sz[y];
		}
	}
}

inline int getroot(int cur,int father,int cursz)
{
	int i,y;
	for (i=head[cur];i;i=nxt[i])
	{
		y=to[i];
		if (y!=father && !taboo[y] && sz[y]>cursz/2) return getroot(y,cur,cursz);
	}
	return cur;
}

inline void Dfs(int cur,int father,int curdepth)
{
	int i,y;
	/*---Do something---*/
	for (i=head[cur];i;i=nxt[i])
	{
		y=to[i];
		if (y!=father && !taboo[y])
		{
			Dfs(y,cur,curdepth+f[i]);
			sz[cur]+=sz[y];
		}
	}
}

inline void merge()
{
	/*---Do something---*/
}

inline void solve(int cur,int father,int cursz)
{	
	dfs(cur,-1);int i,y;
	int root=getroot(cur,-1,cursz);
	for (i=head[root];i;i=nxt[i])
	{
		y=to[i];
		if (!taboo[y])
		{
			cdtot=0;
			Dfs(y,root,f[i]);
			Cnt[y]=sz[y];
			merge();
		}
	}
	taboo[root]=true;
	for (i=head[root];i;i=nxt[i])
	{
		y=to[i];
		if (!taboo[y]) solve(y,cur,Cnt[y]);
	}
}

