struct Treap
{
	int left,right;
	int val,priority;
	int sz;
}tree[1500048];
int tot=0,Root;

inline void update(int root)
{
	tree[root].sz=1;
	if (tree[root].left!=-1) tree[root].sz+=tree[tree[root].left].sz;
	if (tree[root].right!=-1) tree[root].sz+=tree[tree[root].right].sz;
}

int Create(int val,int priority,int left,int right)
{
	tree[++tot]=Treap{left,right,val,priority,1};
	update(tot);
	return tot;
}

int LeftSize(int root)
{
	int res=1;
	if (tree[root].left!=-1) res+=tree[tree[root].left].sz;
	return res;
}

Pair split(int root,int key)
{
	if (root==-1) return mp(-1,-1);
	if (tree[root].val>=key)
	{
		Pair splitted=split(tree[root].left,key);
		tree[root].left=splitted.y;
		update(root);
		return mp(splitted.x,root);
	}
	else
	{
		Pair splitted=split(tree[root].right,key);
		tree[root].right=splitted.x;
		update(root);
		return mp(root,splitted.y);
	}
}

Pair split2(int root,int key)
{
	if (root==-1) return mp(-1,-1);
	if (tree[root].val<=key)
	{
		Pair splitted=split2(tree[root].right,key);
		tree[root].right=splitted.x;
		update(root);
		return mp(root,splitted.y);
	}
	else
	{
		Pair splitted=split2(tree[root].left,key);
		tree[root].left=splitted.y;
		update(root);
		return mp(splitted.x,root);
	}
}

Pair split3(int root,int key)
{
	if (root==-1) return mp(-1,-1);
	if (LeftSize(root)>key)
	{
		Pair splitted=split3(tree[root].left,key);
		tree[root].left=splitted.y;
		update(root);
		return mp(splitted.x,root);
	}
	else
	{
		Pair splitted=split3(tree[root].right,key-LeftSize(root));
		tree[root].right=splitted.x;
		update(root);
		return mp(root,splitted.y);
	}
}

int merge(int root1,int root2)
{
	if (root1==-1) return root2;
	if (root2==-1) return root1;
	if (tree[root1].priority<=tree[root2].priority)
	{
		tree[root1].right=merge(tree[root1].right,root2);
		update(root1);
		return root1;
	}
	else
	{
		tree[root2].left=merge(root1,tree[root2].left);
		update(root2);
		return root2;
	}
}

void Treap_insert(int val)
{
	Pair splitted=split(Root,val);
	Root=merge(merge(splitted.x,Create(val,rand(),-1,-1)),splitted.y);
}

void Treap_delete(int val)
{
	Pair splitted=split(Root,val);
	Pair splitted2=split(splitted.y,val+1);
	if (splitted2.x==-1)
		Root=merge(splitted.x,splitted2.y);
	else
		Root=merge(merge(merge(splitted.x,tree[splitted2.x].left),tree[splitted2.x].right),splitted2.y);
}

void Treap_xrank(int val)
{
	Pair splitted=split(Root,val);
	printf("%d\n",1+(splitted.x==-1?0:tree[splitted.x].sz));
	Root=merge(splitted.x,splitted.y);
}

void Treap_rankx(int x)
{
	Pair splitted=split3(Root,x-1);
	Pair splitted2=split3(splitted.y,1);
	printf("%d\n",tree[splitted2.x].val);
	Root=merge(merge(splitted.x,splitted2.x),splitted2.y);
}

void Treap_prev(int val)
{
	Pair splitted=split(Root,val);
	if (splitted.x==-1)
	{
		printf("-2147483647\n");
		Root=merge(splitted.x,splitted.y);
		return;
	}
	Pair splitted2=split3(splitted.x,tree[splitted.x].sz-1);
	printf("%d\n",tree[splitted2.y].val);
	Root=merge(merge(splitted2.x,splitted2.y),splitted.y);
}

void Treap_next(int val)
{
	Pair splitted=split2(Root,val);
	if (splitted.y==-1)
	{
		printf("2147483647\n");
		Root=merge(splitted.x,splitted.y);
		return;
	}
	Pair splitted2=split3(splitted.y,1);
	printf("%d\n",tree[splitted2.x].val);
	Root=merge(merge(splitted.x,splitted2.x),splitted2.y);
}

int main ()
{
	q=getint();Root=-1;tot=0;
	while (q--)
	{
		type=getint();x=getint();
		if (type==1) Treap_insert(x);
		if (type==2) Treap_delete(x);
		if (type==3) Treap_xrank(x);
		if (type==4) Treap_rankx(x);
		if (type==5) Treap_prev(x);
		if (type==6) Treap_next(x);
	}
}
