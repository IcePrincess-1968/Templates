void exgcd(int a,int b,LL &x,LL &y)
{
	if (!b)
	{
		x=1;
		y=0;
		return;
	}
	else
	{
		exgcd(b,a%b,x,y);
		LL t=x;
		x=y;
		y=t-a/b*y;
	}
}
