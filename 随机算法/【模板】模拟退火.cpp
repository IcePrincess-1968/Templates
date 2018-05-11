const int T=100; //初始温度
const double Tmin=1e-8; //结束温度
const double delta=0.99; //降温速率（调参）

inline double calc_function(double x)
{
	//根据需要返回答案
}

int main ()
{
	srand(1968);
	double t,sol,curres,newsol,newres;int i;
	int Ti=5;ans=LINF;
	while (Ti--) //退火次数
	{
		sol=double(rand())/RAND_MAX*100;curres=calc_function(sol);ans=min(ans,curres);t=T;
		while (t>Tmin)
		{
			int ti=5;
			while (ti--)
			{
				newsol=sol+mypow(-1,rand()%2)*t; //新的解，可以与t有关也可以与t无关
				if (newsol+eps>0 && newsol<100+eps)
				{
					newres=calc_function(newsol);
					ans=min(ans,newres);
					if (newres-curres<-eps) //如果新解更优，则一定选新解
					{
						curres=newres;
						sol=newsol;
					}
					else //如果原解更优，则有一定几率选新解，且这个几率随误差增大和温度下降而递减
					{
						double p=exp((newres-curres)/t);
						if (double(rand())/RAND_MAX<p)
						{
							curres=newres;
							sol=newsol;
						}
					}
				}
			}
			t*=delta; //温度下降
		}
	}
}
