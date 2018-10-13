const int MAXN=1e5;

vector<int> v[MAXN+48];
int dfn[MAXN+48],low[MAXN+48],ind=0,tot;
stack<int> s; 

void tarjan(int cur)
{
	int i,to;
	visited[cur]=true;
	dfn[cur]=low[cur]=++ind;
	s.push(cur);
	for (i=0;i<v[cur].size();i++)
	{
		to=v[cur][i];
		if (!dfn[to])
		{
			tarjan(to);
			low[cur]=min(low[cur],low[to]);
		}
		else if (visited[to]) low[cur]=min(low[cur],low[to]);
	}
	if (dfn[cur]==low[cur])
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

int main ()
{
	tot=n;
	for (i=1;i<=n;i++) if (!a[i].ind) tarjan(i);
}
