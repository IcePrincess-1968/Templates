//0-base
//fail[i]表示0~i-1的最长border 
void getfail()
{
	fail[0]=-1;
	int k=-1,j=0;
	while (j<=m-1)
	{
		if (k==-1 || b[j]==b[k])
			fail[++j]=++k;
		else
			k=fail[k];	
	}
}

//统计共有多少个和模式串匹配的子串 
int kmp_count()
{
	int ans=0;
	while (i<=n-1)
	{
		while (i<=n-1 && j<=m-1)
		{
			if (j==-1 || a[i]==b[j])
			{
				i++;
				j++;
			}
			else
				j=fail[j];
		}
		if (j>=m)
		{
			ans++;
			j=fail[j];
		}
	}
	return ans;
}

//返回第一个与模式串匹配的位置 
int kmp_search()
{
	i=0;j=0;
	while (i<=n-1 && j<=m-1)
	{
		if (j==-1 || a[i]==b[j])
		{
			i++;
			j++;
		}
		else
			j=fail[j];
	}
	return j>=m?i+1-m:-1;
}
