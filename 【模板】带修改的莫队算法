//用stack来记录每个格子的更改历史
//注意修改操作中要判断修改的点是否在当前询问范围内 
int a[10048];stack<int> s[10048];
int cnt[1000048];
int ans[10048];
int cur_left,cur_right,cur_num,cur_ans;

struct Query
{
	int ind;
	int left,right,num;
}query[100048];
int q_top;

struct Update
{
	int pos,delta;
}update[100048];
int u_top;

bool cmp(Query x,Query y)
{
	if (x.left/magic!=y.left/magic) return x.left/magic<y.left/magic;
	if (x.right/magic!=y.right/magic) return x.right/magic<y.right/magic;
	return x.num<y.num;
}

sort(query+1,query+q_top+1,cmp);
for (i=query[1].left;i<=query[1].right;i++)
{
    cnt[a[i]]++;
    if (cnt[a[i]]==1) cur_ans++;
}
for (i=1;i<=query[1].num;i++)
{
    a[update[i].pos]=s[update[i].pos].top();
    if (query[1].left<=update[i].pos && update[i].pos<=query[1].right) 
    {
        cnt[a[update[i].pos]]--;
        if (!cnt[a[update[i].pos]]) cur_ans--;
    }
    
    if (query[1].left<=update[i].pos && update[i].pos<=query[1].right)
    {
        cnt[update[i].delta]++;
        if (cnt[update[i].delta]==1) cur_ans++;
    }
    s[update[i].pos].push(update[i].delta);
    a[update[i].pos]=update[i].delta;
}
ans[query[1].ind]=cur_ans;
cur_left=query[1].left;cur_right=query[1].right;cur_num=query[1].num;
for (i=2;i<=q_top;i++)
{
    if (query[i].left<cur_left)
        for (j=cur_left-1;j>=query[i].left;j--)
        {
            cnt[a[j]]++;
            if (cnt[a[j]]==1) cur_ans++;
        }
    if (query[i].left>cur_left)
        for (j=cur_left;j<=query[i].left-1;j++)
        {
            cnt[a[j]]--;
            if (!cnt[a[j]]) cur_ans--;
        }
    if (query[i].right>cur_right)
        for (j=cur_right+1;j<=query[i].right;j++)
        {
            cnt[a[j]]++;
            if (cnt[a[j]]==1) cur_ans++;
        }
    if (query[i].right<cur_right)
        for (j=cur_right;j>=query[i].right+1;j--)
        {
            cnt[a[j]]--;
            if (!cnt[a[j]]) cur_ans--;
        }
    if (cur_num<query[i].num)
        for (j=cur_num+1;j<=query[i].num;j++)
        {
            a[update[j].pos]=s[update[j].pos].top();
            if (query[i].left<=update[j].pos && update[j].pos<=query[i].right)
            {
                cnt[a[update[j].pos]]--;
                if (!cnt[a[update[j].pos]]) cur_ans--;
            }
            if (query[i].left<=update[j].pos && update[j].pos<=query[i].right)
            {
                cnt[update[j].delta]++;
                if (cnt[update[j].delta]==1) cur_ans++;
            }
            s[update[j].pos].push(update[j].delta);
            a[update[j].pos]=update[j].delta;
        }
    if (cur_num>query[i].num)
        for (j=cur_num;j>=query[i].num+1;j--)
        {
            if (query[i].left<=update[j].pos && update[j].pos<=query[i].right)
            {
                cnt[update[j].delta]--;
                if (!cnt[update[j].delta]) cur_ans--;
            }
            s[update[j].pos].pop();
            a[update[j].pos]=s[update[j].pos].top();
            if (query[i].left<=update[j].pos && update[j].pos<=query[i].right)
            {
                cnt[a[update[j].pos]]++;
                if (cnt[a[update[j].pos]]==1) cur_ans++;
            }
        }
    ans[query[i].ind]=cur_ans;
    cur_left=query[i].left;cur_right=query[i].right;cur_num=query[i].num;
}
for (i=1;i<=q;i++) if (ans[i]) printf("%d\n",ans[i]);
