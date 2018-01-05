struct node
{
	int left,right;
	int lson,rson;
	//add:设置变量维护你需要的东西 
}tree[3000048];
int root[200048],tot=0;

void Pushup(int cur)
{
	//add:孩子给父亲更新维护的东西 
}

//初始线段树 
void build(int cur,int left,int right)
{
	tree[cur].left=left;tree[cur].right=right;
	if (left!=right)
	{
		int mid=(left+right)>>1;
		tree[cur].lson=++tot;build(tree[cur].lson,left,mid);
		tree[cur].rson=++tot;build(tree[cur].rson,mid+1,right);
		Pushup(cur);
	}
	else
	{
		tree[cur].lson=tree[cur].rson=-1;
		//add:底层的初始值设定 
	}
}

//加点 
void Insert(int cur,int last,int pos)
{
	tree[cur]=tree[last];
	if (tree[cur].left==tree[cur].right)
	{
		//add:底层的初始值设定 
		return;
	}
	int mid=(tree[cur].left+tree[cur].right)>>1;
	if (pos<=mid)
	{
		tree[cur].lson=++tot;
		Insert(tree[cur].lson,tree[last].lson,pos);
	}
	else
	{
		tree[cur].rson=++tot;
		Insert(tree[cur].rson,tree[last].rson,pos);
	}
	Pushup(cur);
}

/*add 根据需要设定类型*/ query(int cur,int left,int right)
{
	if (left<=tree[cur].left && tree[cur].right<=right)
		return //add:根据需要返回 
	int mid=(tree[cur].left+tree[cur].right)>>1;
	/*add 根据需要设定类型*/ res1=/*add:init*/,res2=/*add init*/;
	if (left<=mid) res1=query(tree[cur].lson,left,right);
	if (mid+1<=right) res2=query(tree[cur].rson,left,right);
	/*add 根据需要设定类型*/ ret;
	//add:计算本层的返回值 
	return ret;
}

