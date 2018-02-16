struct Treap
{
	Treap *left,*right;
	int val,priority;
	int sz;
	void update()
	{
		sz=1;
		if (left!=NULL) sz+=left->sz;
		if (right!=NULL) sz+=right->sz;
	}
}*Root,*res;
typedef pair<Treap*,Treap*> pii;

Treap* Create(int val,int priority,Treap *left,Treap *right)
{
	res=new Treap;
	res->left=left;res->right=right;res->val=val;res->priority=priority;
	res->update();
	return res;
}

int LeftSize(Treap *root)
{
	int res=1;
	if (root->left!=NULL) res+=root->left->sz;
	return res;
}

//split的功能是按照权值key将root分裂成两棵子树,其中权值与key相同的在右子树
pii split(Treap *root,int key)
{
	if (root==NULL) return make_pair<Treap*,Treap*>(NULL,NULL);
	if (root->val>=key)
	{
		pii splitted=split(root->left,key);
		root->left=splitted.y;
		root->update();
		return mp(splitted.x,root);
	}
	else
	{
		pii splitted=split(root->right,key);
		root->right=splitted.x;
		root->update();
		return mp(root,splitted.y);
	}
}

//split2的功能是按照权值key将root分裂成两棵子树,其中权值与key相同的在左子树
pii split2(Treap *root,int key)
{
	if (root==NULL) return make_pair<Treap*,Treap*>(NULL,NULL);
	if (root->val<=key)
	{
		pii splitted=split2(root->right,key);
		root->right=splitted.x;
		root->update();
		return mp(root,splitted.y);
	}
	else
	{
		pii splitted=split2(root->left,key);
		root->left=splitted.y;
		root->update();
		return mp(splitted.x,root);
	}
}

//split3的功能是将前key个分裂到左子树,后面的分裂到右子树
pii split3(Treap *root,int key)
{
	if (root==NULL) return make_pair<Treap*,Treap*>(NULL,NULL);
	//注意这个地方一定要写大于号！
	if (LeftSize(root)>key)
	{
		pii splitted=split3(root->left,key);
		root->left=splitted.y;
		root->update();
		return mp(splitted.x,root);
	}
	else
	{
		pii splitted=split3(root->right,key-LeftSize(root));
		root->right=splitted.x;
		root->update();
		return mp(root,splitted.y);
	}
}

//merge的功能是按照中序遍历后root1在root2之前的原则将root1和root2合并
Treap* merge(Treap *root1,Treap *root2)
{
	if (root1==NULL) return root2;
	if (root2==NULL) return root1;
	if (root1->priority<=root2->priority)
	{
		root1->right=merge(root1->right,root2);
		root1->update();
		return root1;
	}
	else
	{
		root2->left=merge(root1,root2->left);
		root2->update();
		return root2;
	}
}

//插入元素val
void Treap_insert(int val)
{
	pii splitted=split(Root,val);
	Root=merge(merge(splitted.x,Create(val,rand(),NULL,NULL)),splitted.y);
}

//删除元素val(若有多个只删除一个)
void Treap_delete(int val)
{
	pii splitted=split(Root,val);
	pii splitted2=split(splitted.y,val+1);
	if (splitted2.x==NULL)
		Root=merge(splitted.x,splitted2.y);
	else
		Root=merge(merge(merge(splitted.x,splitted2.x->left),splitted2.x->right),splitted2.y);
}

//求元素val的排名(比val小的元素个数+1)
void Treap_xrank(int val)
{
	pii splitted=split(Root,val);
	printf("%d\n",1+(splitted.x==NULL?0:splitted.x->sz));
	Root=merge(splitted.x,splitted.y);
}

//求排名为x的数(将所有数排序后的第x个)
void Treap_rankx(int x)
{
	pii splitted=split3(Root,x-1);
	pii splitted2=split3(splitted.y,1);
	printf("%d\n",splitted2.x->val);
	Root=merge(merge(splitted.x,splitted2.x),splitted2.y);
}

//求val的前驱(比val小且最大的数,没有输出-2147483647)
void Treap_prev(int val)
{
	pii splitted=split(Root,val);
	if (splitted.x==NULL)
	{
		printf("-2147483647\n");
		Root=merge(splitted.x,splitted.y);
		return;
	}
	pii splitted2=split3(splitted.x,splitted.x->sz-1);
	printf("%d\n",splitted2.y->val);
	Root=merge(merge(splitted2.x,splitted2.y),splitted.y);
}

//求val的后继(比val大且最小的数,没有输出2147483647)
void Treap_next(int val)
{
	pii splitted=split2(Root,val);
	if (splitted.y==NULL)
	{
		printf("2147483647\n");
		Root=merge(splitted.x,splitted.y);
		return;
	}
	pii splitted2=split3(splitted.y,1);
	printf("%d\n",splitted2.x->val);
	Root=merge(merge(splitted.x,splitted2.x),splitted2.y);
}

int main ()
{
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
