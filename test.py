int lower_bound=2805;
    int upper_bound=2821;
    while (lower_bound<=upper_bound)
    {
        int a,b,c,d;
        a=lower_bound/1000;
        b=(lower_bound/100)%10;
        c=(lower_bound/10)%10;
        d=(((lower_bound%1000)%100)%10);
        // printf("%d %d %d %d ",a,b,c,d);
        if(((a%2==0)&&(b%2==0)&&(c%2==0)&&(d%2==0)==1))
        {
            print(lower_bound);
        }
        lower_bound++;
    }