//O(n*logn*logn) 
int rank[1000048],tmp[1000048],sa[1000048],lcp[1000048];
char s[1000048];
int len,k;

bool compare_sa(int x,int y)
{
	if (rank[x]!=rank[y]) return rank[x]<rank[y];
	int tmp1=x+k<=len?rank[x+k]:-1,tmp2=y+k<=len?rank[y+k]:-1;
	return tmp1<tmp2;
}

void construct_sa()
{
	int i;
	for (i=1;i<=len;i++)
	{
		sa[i]=i;
		rank[i]=s[i];
	}
	int cnt;
	for (k=0;k<=len;k==0?k++:k*=2)
	{
		sort(sa+1,sa+len+1,compare_sa);
		tmp[sa[1]]=1;cnt=0;
		for (i=2;i<=len;i++)
		{
			tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
			cnt+=(tmp[sa[i]]!=tmp[sa[i-1]]);
		}
		for (i=1;i<=len;i++) rank[i]=tmp[i];
		if (cnt>=len-1) break;//若已经完全有序则直接退出，重要优化 
	}
}

//rank[i]表示原串中第i个字符开始的后缀在sa数组中的位置 
//lcp[i]记录sa[i]和sa[i+1]起始的后缀的最长公共前缀 
void construct_lcp()
{
	int i,j,h=0;
	for (i=1;i<=len;i++) rank[sa[i]]=i;
	for (i=1;i<=len;i++)
	{
		j=sa[rank[i]-1];
		if (h) h--;
		while (i+h<=len && j+h<=len && s[i+h]==s[j+h]) h++;
		lcp[rank[i]-1]=h;
	}
}
