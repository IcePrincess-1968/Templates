void tarjan(int cur)
{
	int i,to;
	visited[cur]=true;
	a[cur].ind=a[cur].low=++ind;
	s.push(cur);
	for (i=0;i<v[cur].size();i++)
	{
		to=v[cur][i];
		if (!a[to].ind)
		{
			tarjan(to);
			a[cur].low=min(a[cur].low,a[to].low);
		}
		else if (visited[to])
		{
			a[cur].low=min(a[cur].low,a[to].low);
		}
	}
	if (a[cur].ind==a[cur].low)
	{
		tot++;
		int v1;
		do
		{
			v1=s.top();
			anc[v1]=tot;
			w[tot]+=w[v1];
			visited[v1]=false;
			s.pop();
		}
		while (v1!=cur);
	}
}

tot=n;
for (i=1;i<=n;i++) if (!a[i].ind) tarjan(i);
