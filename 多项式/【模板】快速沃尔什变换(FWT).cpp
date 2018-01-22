//fl=1表示FWT,fl=-1表示uFWT
void FWT(LL c[],int len,int fl)
{
	int clen,j,k;
	for (clen=2;clen<=len;clen<<=1)
		for (j=0;j<len;j+=clen)
			for (k=j;k<j+(clen>>1);k++)
			{
				LL tmp1=c[k],tmp2=c[k+(clen>>1)];
                //对于xor
                if (fl==1) c[k]=tmp1+tmp2,c[k+(clen>>1)]=tmp1-tmp2; else c[k]=(tmp1+tmp2)>>1,c[k+(clen>>1)]=(tmp1-tmp2)>>1;
                //对于and
                //if (fl==1) c[k]=tmp1+tmp2; else c[k]=tmp1-tmp2;
                //对于or
                //if (fl==1) c[k+(clen>>1)]=tmp1+tmp2; else c[k+(clen>>1)]=tmp2-tmp1;
            }
}

void calc_FWT()
{
	FWT(a,1<<n,1);
	FWT(b,1<<n,1);
	for (int i=0;i<=(1<<n)-1;i++) a[i]*=b[i];
	FWT(a,1<<n,-1);
}