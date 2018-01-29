bool state[100048];int result[100048];
vector<int> v[100048];

bool find(int cur)
{
	int i;
	for (i=0;i<v[cur].size();i++)
		//state数组指的是如果之前曾试图改变v[cur][i]的归属
		//因为还在find函数内，所以必然是已经失败了的，所以
		//不用再浪费时间了
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
