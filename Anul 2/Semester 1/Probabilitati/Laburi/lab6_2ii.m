function lab6_2ii(n)
    g = @(x) abs(sin(exp(x)));
    int_g_1 = lab6_2iMC1(g,-1,3,n)  
    int_g_2 = lab6_2iMC2(g,-1,3,n)
    int_g_3 = quad(g,-1,3)
end