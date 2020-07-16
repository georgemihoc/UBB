function lab6_2i(n)
    g = @(x) exp(-x.^2);
    int_g_1 = lab6_2iMC1(g,-2,2,n)  
    int_g_2 = lab6_2iMC2(g,-2,2,n)
    int_g_3 = quad(g,-2,2)
end