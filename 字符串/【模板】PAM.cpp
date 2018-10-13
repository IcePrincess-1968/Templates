// 注意有一个奇数长度根和一个偶数长度根 
namespace PAM
{
	struct node
	{
		int nxt[11];
		int len,fail,val;
	}tree[MAXN*2];int tot,last;
	inline void init()
	{
		tree[0].fail=1;tree[1].len=-1;tot=1;last=0;
	}
	inline void insert(int pos)
	{
		int w=s[pos]-'0';
		while (s[pos-tree[last].len-1]!=s[pos]) last=tree[last].fail;
		if (!tree[last].nxt[w])
		{
			++tot;
			tree[tot].len=tree[last].len+2;
			if (tree[tot].len==1)
				tree[tot].val=w;
			else
				tree[tot].val=add(add(1ll*tree[last].val*10%MOD+1ll*w*Val[tree[tot].len]%MOD)+w);
			ans=add(ans+tree[tot].val);
			int tmp=tree[last].fail;
			while (s[pos-tree[tmp].len-1]!=s[pos]) tmp=tree[tmp].fail;
			tree[tot].fail=tree[tmp].nxt[w];
			tree[last].nxt[w]=tot;
			last=tot;
		}
		else
			last=tree[last].nxt[w];
	}
}
