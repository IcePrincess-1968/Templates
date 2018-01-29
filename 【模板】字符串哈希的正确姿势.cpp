typedef pair<LL,LL> pii;
const int p=19260817;
const int MOD1=1e9+7,MOD2=998244353;

int n;
char s[1548];int len;

pii gethash()
{
	LL res1=0,res2=0;int i;
	for (i=1;i<=len;i++)
	{
		res1=(res1*p+s[i])%MOD1;
		res2=(res2*p+s[i])%MOD2;
	}
	return mp(res1,res2);
}