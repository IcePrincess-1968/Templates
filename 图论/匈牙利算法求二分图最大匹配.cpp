bool state[100048];int result[100048];
vector<int> v[100048];

bool find(int cur)
{
	int i;
	for (i=0;i<v[cur].size();i++)
		if (!state[v[cur][i]])
		{
			state[v[cur][i]]=true;
			if (!result[v[cur][i]] || find(result[v[cur][i]]))
			{
				result[v[cur][i]]=cur;
				return true;
			}
		}
}

int main ()
{
    int i,ans=0;
    for (i=1;i<=n;i++)
    {
        memset(state,false,sizeof(state));
        if (find(i)) ans++;
    }
}
