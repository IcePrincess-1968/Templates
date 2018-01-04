const double eps=1e-10;

bool taken[148];
//值为true表示这是一个有效方程 
int t,n;
//n未知数个数,t方程个数 

inline double myabs(LL x)
{
	return x>=0?x:-x;
}

inline void Remove(int r1,int r2)
{
	double tmp=b[r2][col];
	for (int i=1;i<=n+1;i++) b[r2][i]-=b[r1][i]*tmp;
}

void solve()
{
	int i,j,rr;
	//消元
	//注意不要用long long求lcm而是用double，不然会爆long long 
	for (j=1;j<=n;j++)
	{
		rr=1
		while (rr<=t && (taken[rr] || myabs(b[rr][j])<eps)) rr++;
		if (rr>t) continue; //有自由元，说明有多解 
		taken[rr]=true;
		if (myabs(b[rr][j]-1.0)>eps)
		{
			double tmp=b[rr][j];
			for (i=1;i<=n+1;i++) b[rr][i]/=tmp;
		}
		for (i=1;i<=t;i++) if (!taken[i] && myabs(b[i][j])>eps) Remove(i,rr);
	}
}

int main ()
{
	//init
	solve();
	int i,j,Free=n;
	for (i=1;i<=t;i++) if (taken[i]) Free--;
	//自由元个数=Free 
}
