const int MAXN=1e5;

struct Edge
{
	int u,v,c;
}edge[MAXN+48];

vector<int> v[MAXN+48],vv[MAXN+48];
int dfn[MAXN+48],low[MAXN+48],Index=0,ind=n;
stack<int> s;

inline bool check(int id,Pair E)
{
	if (edge[id].x==E.x && edge[id].y==E.y) return true;
	if (edge[id].x==E.y && edge[id].y==E.x) return true;
	return false;
}

inline void tarjan(int cur,int father)
{
	dfn[cur]=low[cur]=++Index;int i,j,x,y,id,u;
	for (i=0;i<int(v[cur].size());i++)
	{
		y=(edge[v[cur][i]].x==cur?edge[v[cur][i]].y:edge[v[cur][i]].x);
		if (!dfn[y])
		{
			s.push(v[cur][i]);tarjan(y,cur);
			low[cur]=min(low[cur],low[y]);
			if (low[y]>=dfn[cur])
			{
				if (check(s.top(),mp(cur,y))) continue;
				++ind;int pre=cur;
				do
				{
					id=s.top();s.pop();	
					x=edge[id].x;u=edge[id].y;
					if (x==pre) swap(x,u);
					vv[ind].pb(x);
					pre=x;
				}
				while (!check(id,mp(cur,y)));
			}
		}
		else if (y!=father && dfn[y]<dfn[cur])
		{
			s.push(v[cur][i]);
			low[cur]=min(low[cur],low[y]);
		}
	}
}

