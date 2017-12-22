//插入或删除之后按照需要对要维护的东西进行更新 
void update(Treap *root)
{
	
}

//创造一个新的节点以插入treap 
Treap *res;
static Treap* Create(int value,int priority,Treap *left,Treap *right)
{	
	res=new Treap;
	res->value=value;res->priority=priority;
	res->left=left;res->right=right;
	update(res);
	return res;
}

//按照要插入的值key将treap拆成两棵子树 
pii split(Treap *root,int key)
{
	if (root==NULL) return make_pair<Treap*,Treap*>(NULL,NULL);
	if (root->value<=key)
	{
		pii splitted=split(root->right,key);
		root->right=splitted.x;
		update(root);
		return mp(root,splitted.y);
	}
	else
	{
		pii splitted=split(root->left,key);
		root->left=splitted.y;
		update(root);
		return mp(splitted.x,root);
	}
}

//向treap中加入值为key的点 
Treap* add(Treap *root,int key,int priority)
{
	if (root==NULL) return Create(key,priority,NULL,NULL);
	if (priority>root->priority)
	{
		pii splitted=split(root,key);
		return Create(key,priority,splitted.x,splitted.y);
	}
	else
	{
		if (root->value<=key)
		{
			root->right=add(root->right,key,priority);
			update(root);
			return root;
		}
		else
		{
			root->left=add(root->left,key,priority);
			update(root);
			return root;
		}
	}
}

//把两棵treap子树合并 
Treap* merge(Treap *root1,Treap *root2)
{
	if (root1==NULL) return root2;
	if (root2==NULL) return root1;
	if (root1->value<=root2->value)
	{
		root1->right=merge(root1->right,root2);
		update(root1);
		return root1;
	}
	else
	{
		root2->left=merge(root1,root2->left);
		update(root2);
		return root2;
	}
}

//删除值为key的点（有多个只删一个） 
Treap* Delete(Treap *root,int key)
{
	if (root==NULL) return NULL;
	if (key==root->value) return merge(root->left,root->right);
	if (root->value<key)
	{
		root->right=Delete(root->right,key);
		update(root);
		return root;
	}
	else
	{
		root->left=Delete(root->left,key);
		update(root);
		return root;
	}
}
