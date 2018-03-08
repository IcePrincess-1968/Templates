struct LinerBase
{
    LL d[60];
    inline void init()
    {
        for (int i=0;i<=50;i++) d[i]=0;
    }
    inline void add(LL x)
    {
        int i;
        for (i=50;i>=0;i--)
        {
            if ((x>>i)&1)
                if (d[i]==0)
                {
                    d[i]=x;
                    break;
                }
                else
                    x^=d[i];
        }
    }
    inline LL querymax()
    {
        LL res=0;int i;
        for (i=50;i>=0;i--)
            if ((res^d[i])>res) res^=d[i];
        return res;
    }
};
