struct node
{
	int left,right;
	int lson,rson;
	//add:���ñ���ά������Ҫ�Ķ��� 
}tree[3000048];
int root[200048],tot=0;

void Pushup(int cur)
{
	//add:���Ӹ����׸���ά���Ķ��� 
}

//��ʼ�߶��� 
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
		//add:�ײ�ĳ�ʼֵ�趨 
	}
}

//�ӵ� 
void Insert(int cur,int last,int pos)
{
	tree[cur]=tree[last];
	if (tree[cur].left==tree[cur].right)
	{
		//add:�ײ�ĳ�ʼֵ�趨 
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

/*add ������Ҫ�趨����*/ query(int cur,int left,int right)
{
	if (left<=tree[cur].left && tree[cur].right<=right)
		return //add:������Ҫ���� 
	int mid=(tree[cur].left+tree[cur].right)>>1;
	/*add ������Ҫ�趨����*/ res1=/*add:init*/,res2=/*add init*/;
	if (left<=mid) res1=query(tree[cur].lson,left,right);
	if (mid+1<=right) res2=query(tree[cur].rson,left,right);
	/*add ������Ҫ�趨����*/ ret;
	//add:���㱾��ķ���ֵ 
	return ret;
}

