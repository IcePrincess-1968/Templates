struct Treap
{
	Treap *left,*right;
	int value,priority;
	int sz,flip;
	//更新子树的大小 
	void update()
	{
	    sz=1;
	    if (left!=NULL) sz+=left->sz;
	    if (right!=NULL) sz+=right->sz;
	}
	//下放表示旋转的flip变量 
	void pushdown()
	{
		if (flip)
		{
			if (left!=NULL) left->flip^=1;
			if (right!=NULL) right->flip^=1;
			flip^=1;
			swap(left,right);
		}
	}
}*Root,*res;
typedef pair<Treap*,Treap*> pii;

Treap* Create(int key,int priority,Treap *left,Treap *right)
{
	res=new Treap;
	res->value=key;res->priority=priority;
	res->left=left;res->right=right;res->flip=0;
	res->update();
	return res;
}

//计算左子树（包括根节点）的总大小 
inline int LeftSize(Treap *root)
{
	int ret=1;
	if (root->left!=NULL) ret+=root->left->sz;
	return ret; 
}

//将前key个split到第一棵子树中，后面的split到第二棵子树中 
pii split(Treap *root,int key)
{
	if (root==NULL) return make_pair<Treap*,Treap*> (NULL,NULL);
	root->pushdown();
	if (LeftSize(root)<=key)
	{ 
	    pii splitted=split(root->right,key-LeftSize(root));
	    root->right=splitted.x;
	    root->update();
	    return mp(root,splitted.y);
	}
	else
	{
	    pii splitted=split(root->left,key);
	    root->left=splitted.y;
	    root->update();
	    return mp(splitted.x,root);
	}
}

//合并两棵子树 
Treap* merge(Treap *root1,Treap *root2)
{                                                                                                                     
	if (root1==NULL) return root2;
	if (root2==NULL) return root1;
	if (root1->priority<=root2->priority)
	{
		root1->pushdown();
		root1->right=merge(root1->right,root2);
		root1->update();
		return root1;
	}
	else
	{
		root2->pushdown();
		root2->left=merge(root1,root2->left);
		root2->update();
		return root2;
	}
}

void print(Treap *root)
{
	if (root==NULL) return;
	root->pushdown();
	if (root->left!=NULL) print(root->left);
	printf("%d ",root->value);
	if (root->right!=NULL) print(root->right);
}

int main ()
{
	while (q--)
	{
	    l=getint();r=getint();
	    pii sx=split(Root,l-1);
	    pii sy=split(sx.y,r-l+1);
	    sy.x->flip^=1;
	    Root=merge(merge(sx.x,sy.x),sy.y);
	}
	print(Root);
}
