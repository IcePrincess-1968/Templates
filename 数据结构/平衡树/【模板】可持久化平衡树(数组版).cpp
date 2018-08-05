struct Treap
{
    int left,right;
    int val,priority;
    int sz;
}tree[500048*50];
int root[500048];
int tot=0,rtot=0;

inline void update(int root)
{
    tree[root].sz=1;
    if (tree[root].left!=-1) tree[root].sz+=tree[tree[root].left].sz;
    if (tree[root].right!=-1) tree[root].sz+=tree[tree[root].right].sz;
}

int Create(int val,int priority,int left,int right)
{
    tree[++tot]=Treap{left,right,val,priority,0};
    update(tot);
    return tot;
}

void cop(int &a,int b)
{
    if (b==-1) a=-1; else a=Create(0,rand(),-1,-1),tree[a]=tree[b];
}

int LeftSize(int root)
{
    int res=1;
    if (tree[root].left!=-1) res+=tree[tree[root].left].sz;
    return res;
}

void split(int root,int &a,int &b,int key)
{
    if (root==-1)
    {
        a=-1;b=-1;
        return;
    }
    if (tree[root].val>=key)
    {
        cop(b,root);
        split(tree[root].left,a,tree[b].left,key);
        update(b);
    }
    else
    {
        cop(a,root);
        split(tree[root].right,tree[a].right,b,key);
        update(a);
    }
}

void split2(int root,int &a,int &b,int key)
{
    if (root==-1)
    {
        a=-1;b=-1;
        return;
    }
    if (tree[root].val<=key)
    {
        cop(a,root);
        split2(tree[root].right,tree[a].right,b,key);
        update(a);
    }
    else
    {
        cop(b,root);
        split2(tree[root].left,a,tree[b].left,key);
        update(b);
    }
}

void split3(int root,int &a,int &b,int key)
{
    if (root==-1)
    {
        a=-1;b=-1;
        return;
    }
    if (LeftSize(root)>key)
    {
        cop(b,root);
        split3(tree[root].left,a,tree[b].left,key);
        update(b);
    }
    else
    {
        cop(a,root);
        split3(tree[root].right,tree[a].right,b,key-LeftSize(root));
        update(a);
    }
}

void merge(int root1,int root2,int &res)
{
    if (root1==-1) {res=root2;return;}
    if (root2==-1) {res=root1;return;}
    if (tree[root1].priority<=tree[root2].priority)
    {
        cop(res,root1);
        merge(tree[root1].right,root2,tree[res].right);
    }
    else
    {
        cop(res,root2);
        merge(root1,tree[root2].left,tree[res].left);
    }
    update(res);
}

void Treap_insert(int rt,int val)
{
    Pair splitted;split(root[rt],splitted.x,splitted.y,val);
    int tmp=-1;
    merge(splitted.x,Create(val,rand(),-1,-1),tmp);
    merge(tmp,splitted.y,root[++rtot]);
}

void Treap_delete(int rt,int val)
{
    Pair splitted;split(root[rt],splitted.x,splitted.y,val);
    Pair splitted2;split3(splitted.y,splitted2.x,splitted2.y,1);
    if (splitted2.x==-1 || tree[splitted2.x].val==val)
        merge(splitted.x,splitted2.y,root[++rtot]);
    else
        cop(root[++rtot],root[rt]);
}

void Treap_xrank(int rt,int val)
{
    Pair splitted;split(root[rt],splitted.x,splitted.y,val);
    printf("%d\n",1+(splitted.x==-1?0:tree[splitted.x].sz));
    cop(root[++rtot],root[rt]);
}

void Treap_rankx(int rt,int key)
{
    Pair splitted;split3(root[rt],splitted.x,splitted.y,key-1);
    Pair splitted2;split3(splitted.y,splitted2.x,splitted2.y,1);
    printf("%d\n",tree[splitted2.x].val);
    cop(root[++rtot],root[rt]);
}

void Treap_prev(int rt,int val)
{
    Pair splitted;split(root[rt],splitted.x,splitted.y,val);
    if (splitted.x==-1)
    {
        printf("-2147483647\n");
        cop(root[++rtot],root[rt]);
        return;
    }
    Pair splitted2;split3(splitted.x,splitted2.x,splitted2.y,tree[splitted.x].sz-1);
    printf("%d\n",tree[splitted2.y].val);
    cop(root[++rtot],root[rt]);
}

void Treap_next(int rt,int val)
{
    Pair splitted;split2(root[rt],splitted.x,splitted.y,val);
    if (splitted.y==-1)
    {
        printf("2147483647\n");
        cop(root[++rtot],root[rt]);
        return;
    }
    Pair splitted2;split3(splitted.y,splitted2.x,splitted2.y,1);
    printf("%d\n",tree[splitted2.x].val);
    cop(root[++rtot],root[rt]);
}

int main ()
{
    int q,type,rt,x;
    q=getint();rtot=tot=0;
    root[0]=-1;
    while (q--)
    {
        rt=getint();type=getint();x=getint();
        if (type==1) Treap_insert(rt,x);
        if (type==2) Treap_delete(rt,x);
        if (type==3) Treap_xrank(rt,x);
        if (type==4) Treap_rankx(rt,x);
        if (type==5) Treap_prev(rt,x);
        if (type==6) Treap_next(rt,x);
    }
    return 0;
}
