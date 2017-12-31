void tarjan(int cur,int father)
{
	dfn[cur]=low[cur]=++ind;
	int i,to;
	for (i=0;i<v[cur].size();i++)
	{
		to=edge[v[cur][i]].x==cur?edge[v[cur][i]].y:edge[v[cur][i]].x;
		if (!dfn[to])
		{
			tarjan(to,cur);
			low[cur]=min(low[cur],low[to]);
			if (low[to]>dfn[cur]) isbridge[v[cur][i]]=true;
		}
		else if (to!=father) low[cur]=min(low[cur],low[to]);
	}
}

void dfs(int cur,int par)
{
	visited[cur]=true;
	anc[cur]=par;
	int i,to;
	for (i=0;i<v[cur].size();i++)
	{
		if (isbridge[v[cur][i]]) continue;
		to=(edge[v[cur][i]].x==cur?edge[v[cur][i]].y:edge[v[cur][i]].x);
		if (!visited[to]) dfs(to,par);
	}
}
