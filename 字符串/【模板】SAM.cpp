const int MAXN=1e6+48;

char s[MAXN+48];int len;
vector<int> v[MAXN*2];int sz[MAXN*2];
//sz数组当前记录的是SAM的这个节点是否包含一个新的后缀 
//在parent树上对SAM做一遍深搜，统计sz的子树和，可以得到每个节点的right集合大小 

namespace SAM
{
	int tot,nxt[MAXN*2][27],par[MAXN*2],maxn[MAXN*2],root,last;
	inline void init() {tot=1;root=last=1;}
	inline void insert(char ch)
	{
		int p=last,np=++tot;maxn[np]=maxn[p]+1;sz[np]=1;int w=ch-'a'+1;
		while (p && !nxt[p][w]) nxt[p][w]=np,p=par[p];
		if (!p) {par[np]=root;last=np;return;}
		int q=nxt[p][w];
		if (maxn[q]==maxn[p]+1) {par[np]=q;last=np;return;}
		int nq=++tot;maxn[nq]=maxn[p]+1;
		memcpy(nxt[nq],nxt[q],sizeof(nxt[q]));
		par[nq]=par[q];par[np]=nq;par[q]=nq;
		while (p && nxt[p][w]==q) nxt[p][w]=nq,p=par[p];
		last=np;
	}
}
