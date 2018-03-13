//初始插入字符，建Trie
void Insert(int ind)
{
	int i,j,cur=1,len=strlen(s+1);
	for (i=1;i<=len;i++)
	{
		if (!trie[cur].next[s[i]])
		{
			trie[cur].next[s[i]]=++tot;
			for (j=1;j<=128;j++) trie[tot].next[j]=0;
			trie[tot].fail=trie[tot].ind=0;
		}
		cur=trie[cur].next[s[i]];
		if (i==len) trie[cur].ind=ind;
	}
}

//构建fail指针(Trie图)
//fail[cur]指的是当前已经匹配到cur这个字符，它的那些儿子们都失配时，该转移到哪里继续匹配
queue<int> q;
void construct_fail()
{
	int i,cur,tmp;q.push(1);
	while (!q.empty())
	{
		cur=q.front();q.pop();
		for (i=1;i<=128;i++)
			if (trie[cur].next[i])
			{
				tmp=trie[cur].fail;
				while (tmp && !trie[tmp].next[i]) tmp=trie[tmp].fail;
				trie[trie[cur].next[i]].fail=(tmp?trie[tmp].next[i]:1);
				q.push(trie[cur].next[i]);
			}
			else
			    //构建Trie图（不是很必要），如果没有i这个儿子，就可以通过fail指针提前帮他找好下一个匹配位置
				trie[cur].next[i]=(cur==1?1:trie[trie[cur].fail].next[i]);
	}
}

//匹配
void query()
{
	int i,cur=1,tmp,len=strlen(s+1);
	for (i=1;i<=len;i++)
	{
		cur=trie[cur].next[s[i]];
		tmp=cur;
		while (tmp)
		{
			if (trie[tmp].ind) cnt[trie[tmp].ind]++;
			tmp=trie[tmp].fail;
		}
	}
}
