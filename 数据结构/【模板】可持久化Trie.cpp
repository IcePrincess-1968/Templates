//������Trie�����Դ���int��Χ�ڵ�����
//���ȷ�����ķ�Χ�����ռ��ʱ��,���Ըտ�ʼ��һ����Trie,�Ӷ�������-1��ָ�룬������Դ������ 
struct Trie
{
	int lson,rson;
	int cnt;
}tree[15000048];
int tot;

int num[64],ansnum[64];
inline void TEN_TO_TWO(int x)
{
	int i;
	for (i=1;i<=25;i++)
		if (x&(1<<(i-1))) num[25-i+1]=1; else num[25-i+1]=0;
}
inline int TWO_TO_TEN()
{
	int i,res=0;
	for (i=25;i>=1;i--) res+=ansnum[i]*(1<<(25-i));
	return res;
}

void Insert(int last,int cur,int depth)
{
	if (last!=-1)
		tree[cur]=tree[last];
	else
		tree[cur].lson=tree[cur].rson=-1;
	if (depth==25)
	{
		tree[cur].cnt++;
		return;
	}
	if (num[depth+1]==0)
	{
		tree[cur].lson=++tot;
		Insert(tree[last].lson,tree[cur].lson,depth+1);
	}
	else
	{
		tree[cur].rson=++tot;
		Insert(tree[last].rson,tree[cur].rson,depth+1);
	}
	tree[cur].cnt=0;
	if (tree[cur].lson!=-1) tree[cur].cnt+=tree[tree[cur].lson].cnt;
	if (tree[cur].rson!=-1) tree[cur].cnt+=tree[tree[cur].rson].cnt;
}

void Generate(int left,int right,int depth)
{
	if (depth==25) return;
	if (num[depth+1]==0)
	{
		int tmp=tree[right].rson==-1?0:tree[tree[right].rson].cnt;
		tmp-=tree[left].rson==-1?0:tree[tree[left].rson].cnt;
		if (tmp>0)
		{
			ansnum[depth+1]=1;
			Generate(tree[left].rson,tree[right].rson,depth+1);
		}
		else
		{
			ansnum[depth+1]=0;
			Generate(tree[left].lson,tree[right].lson,depth+1);
		}
	}
	else
	{
		int tmp=tree[right].lson==-1?0:tree[tree[right].lson].cnt;
		tmp-=tree[left].lson==-1?0:tree[tree[left].lson].cnt;
		if (tmp>0)
		{
			ansnum[depth+1]=0;
			Generate(tree[left].lson,tree[right].lson,depth+1);
		}
		else
		{
			ansnum[depth+1]=1;
			Generate(tree[left].rson,tree[right].rson,depth+1);
		}
	}
}

int query(int left,int right,int depth)
{
	if (depth==25)
	{
		int res=right==-1?0:tree[right].cnt;
		res-=left==-1?0:tree[left].cnt;
		return res;
	}
	if (num[depth+1]==0)
		return query(tree[left].lson,tree[right].lson,depth+1);
	else
	{
		int tmp=tree[right].lson==-1?0:tree[tree[right].lson].cnt;
		tmp-=(tree[left].lson==-1)?0:tree[tree[left].lson].cnt;
		return tmp+query(tree[left].rson,tree[right].rson,depth+1);
	}
}

void Generate_kth(int left,int right,int depth,int k)
{
	if (depth==25) return;
	int tmp=tree[right].lson==-1?0:tree[tree[right].lson].cnt;
	tmp-=tree[left].lson==-1?0:tree[tree[left].lson].cnt;
	if (k>tmp)
	{
		ansnum[depth+1]=1;
		Generate_kth(tree[left].rson,tree[right].rson,depth+1,k-tmp);
	}
	else
	{
		ansnum[depth+1]=0;
		Generate_kth(tree[left].lson,tree[right].lson,depth+1,k);
	}
}

int pos[500048];
//��¼��ǰ���еĵ�i��������Ӧ��Trie������ 

//����0:�����е���������x 
//����1:������[L,R]����x���ֵ������ 
//����2:ɾ�����е����x����
//����3:������[L,R]�ڲ�����x��ֵ�ĸ���
//����4:������[L,R]�ڴ�С�������еĵ�k���� 
int main ()
{
	root[0]=++tot;
	tree[root[0]].lson=tree[root[0]].rson=-1;
	int cur=0,nn=0;
	while (Query--)
	{
		type=getint();
		if (type==0)
		{
			x=getint();
			TEN_TO_TWO(x);
			root[++nn]=++tot;
			pos[cur+1]=nn;
			Insert(root[pos[cur]],root[nn],0);
			cur++;
		}
		if (type==1)
		{
			L=getint();R=getint();x=getint();
			TEN_TO_TWO(x);
			Generate(root[pos[L-1]],root[pos[R]],0);
			printf("%d\n",TWO_TO_TEN());
		}
		if (type==2)
		{
			x=getint();
			cur-=x;
		}
		if (type==3)
		{
			L=getint();R=getint();x=getint();
			TEN_TO_TWO(x);
			printf("%d\n",query(root[pos[L-1]],root[pos[R]],0));
		}	
		if (type==4)
		{
			L=getint();R=getint();x=getint();
			Generate_kth(root[pos[L-1]],root[pos[R]],0,x);
			printf("%d\n",TWO_TO_TEN());
		}
	}
}
