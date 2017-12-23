//ss原串；s加过"#"的串 
//RL[i]：pos=i的最长半径 
cur=1;
len=strlen(ss+1);
for (i=1;i<=len;i++)
{
	s[cur++]='#';
	s[cur++]=ss[i];
}
s[cur]='#';
len=cur;
maxright=pos=0;
int ans=0;
for (i=1;i<=len;i++)
{
	if (i<maxright)
		RL[i]=min(RL[2*pos-i],maxright-i);
	else
		RL[i]=1;
	while (i-RL[i]>=1 && i+RL[i]<=len && s[i-RL[i]]==s[i+RL[i]]) RL[i]++;
	ans=max(ans,RL[i]-1);
	if (i+RL[i]>maxright)
	{
		maxright=i+RL[i];
		pos=i;
	}
}
printf("%d\n",ans);
