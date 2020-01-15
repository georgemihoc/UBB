function lab6_2iii(n)
    g = @(x) x.^2./(1+x.^2).*(-1<=x & x<=0)...
        +sqrt(2*x - x.^2).*(0<x & x<=2)
    int_g_1 = lab6_2iMC1(g,-1,2,n)  
    int_g_2 = lab6_2iMC2(g,-1,2,n)
    int_g_3 = quad(g,-1,2)
end