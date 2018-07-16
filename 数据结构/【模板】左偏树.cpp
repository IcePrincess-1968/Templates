namespace LeftistTree
{
	int lson[MAXN+48],rson[MAXN+48],sz[MAXN+48],val[MAXN+48],h[MAXN+48],tot=0;LL sum[MAXN+48];
	inline int newtree(int vv)
	{
		++tot;lson[tot]=rson[tot]=0;
		sz[tot]=1;sum[tot]=val[tot]=vv;
		h[tot]=1;
		return tot;
	}
	inline int merge(int x,int y)
	{
		if (!x || !y) return x+y;
		if (val[x]<val[y]) swap(x,y);
		rson[x]=merge(rson[x],y);
		if (h[lson[x]]<h[rson[x]]) swap(lson[x],rson[x]);
		h[x]=h[rson[x]]+1;
		sz[x]=sz[lson[x]]+sz[rson[x]]+1;
		sum[x]=sum[lson[x]]+sum[rson[x]]+val[x];
		return x;
	}
	inline int pop(int x) {return merge(lson[x],rson[x]);}
}
