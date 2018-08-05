const int MAXN=5e5;

namespace splay
{
    struct node
    {
        int val,ch[2],father,sz,cnt;
        inline void clean() {sz=cnt=father=val=ch[0]=ch[1]=0;}
    }tree[MAXN+48];int tot=0,root;
    inline void print(int cur)
    {
        if (tree[cur].ch[0]) print(tree[cur].ch[0]);
        cout<<tree[cur].val<<endl;
        if (tree[cur].ch[1]) print(tree[cur].ch[1]);
    }
    inline void update(int cur) {if (cur) tree[cur].sz=tree[cur].cnt+tree[tree[cur].ch[0]].sz+tree[tree[cur].ch[1]].sz;}
    inline void rotate(int x)
    {
        int y=tree[x].father,z=tree[y].father;
        int k=(tree[y].ch[1]==x);
        tree[z].ch[tree[z].ch[1]==y]=x;
        tree[y].ch[k]=tree[x].ch[k^1];
        tree[x].ch[k^1]=y;
        tree[x].father=z;tree[y].father=x;tree[tree[y].ch[k]].father=y;
        update(y);update(x);
    }
    inline void splay(int x,int target)
    {
        while (tree[x].father!=target)
        {
            int y=tree[x].father,z=tree[y].father;
            if (z!=target)
                ((tree[z].ch[1]==y)^(tree[y].ch[1]==x))?rotate(x):rotate(y);
            rotate(x);
        }
        if (!target) root=x;
    }
    inline int find(int val)
    {
        int cur=root,res=0;
        for (;;)
        {
            if (tree[cur].val==val) {res+=tree[tree[cur].ch[0]].sz;splay(cur,0);break;}
            if (val<tree[cur].val)
            {
                if (!tree[cur].ch[0]) break;
                cur=tree[cur].ch[0];
            }
            else
            {
                res+=tree[tree[cur].ch[0]].sz+tree[cur].cnt;
                if (!tree[cur].ch[1]) break;
                cur=tree[cur].ch[1];
            }
        }
        return res;
    }
    inline int findx(int k)
    {
        int cur=root;
        for (;;)
        {
            if (tree[tree[cur].ch[0]].sz>=k) {cur=tree[cur].ch[0];continue;}
            if (tree[tree[cur].ch[0]].sz+tree[cur].cnt>=k) return tree[cur].val;
            k-=tree[tree[cur].ch[0]].sz;k-=tree[cur].cnt;
            cur=tree[cur].ch[1];
        }
    }
    inline void insert(int val)
    {
        if (!root)
        {
            root=++tot;
            tree[root].ch[0]=tree[root].ch[1]=0;
            tree[root].sz=tree[root].cnt=1;tree[root].val=val;
            return;
        }
        int cur=root,k;
        while (tree[cur].val!=val)
        {
            k=(val>tree[cur].val);
            if (tree[cur].ch[k]) cur=tree[cur].ch[k]; else break;
        }
        if (tree[cur].val==val)
            tree[cur].cnt++,tree[cur].sz++;
        else
        {
            int cc=cur;tree[cur].ch[k]=++tot;cur=tot;
            tree[cur].val=val;tree[cur].cnt=tree[cur].sz=1;
            tree[cur].ch[0]=tree[cur].ch[1]=0;tree[cur].father=cc;
        }
        splay(cur,0);
    }
    inline int find_pre(int val)
    {
        if (!tree[root].ch[0]) return -2147483647;
        int cur=tree[root].ch[0];
        while (tree[cur].ch[1]) cur=tree[cur].ch[1];
        return cur;
    }
    inline int find_nxt(int val)
    {
        if (!tree[root].ch[1]) return 2147483647;
        int cur=tree[root].ch[1];
        while (tree[cur].ch[0]) cur=tree[cur].ch[0];
        return cur;
    }
    inline void del(int val)
    {
        find(val);	
        if (tree[root].cnt>1)
        {
            tree[root].cnt--;tree[root].sz--;
            return;
        }
        if (!tree[root].ch[0] && !tree[root].ch[1])
        {
            tree[root].clean();root=0;
            return;
        }
        if (!tree[root].ch[0] || !tree[root].ch[1])
        {
            int k=(tree[root].ch[1]==0);
            int oldroot=root;root=tree[root].ch[k^1];
            tree[root].father=0;
            tree[oldroot].clean();return;
        }
        int cur=find_pre(val);splay(cur,root);
        int oldroot=root;root=tree[root].ch[0];
        tree[root].ch[1]=tree[oldroot].ch[1];tree[tree[root].ch[1]].father=root;
        tree[root].father=0;
        update(root);tree[oldroot].clean();
    }
}
