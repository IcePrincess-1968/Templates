void tarjan(int cur,int father)
{
	visited[cur]=true;
	dfn[cur]=low[cur]=++ind;
	int i,to,chil=0;
	bool f=false;
	for (i=0;i<v[cur].size();i++)
	{
		to=v[cur][i];
		if (!visited[to])
		{
			tarjan(to,cur);chil++;
			low[cur]=min(low[cur],low[to]);
			if (father==-1 && chil>1 && !f) {ans.pb(cur);f=true;}
			if (father!=-1 && low[to]>=dfn[cur] && !f) {ans.pb(cur);f=true;}
		}
		else if (to!=father) low[cur]=min(low[cur],low[to]);
	}
}

for (i=1;i<=n;i++) if (!dfn[i]) tarjan(i,-1);
