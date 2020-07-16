function int = lab6_2iMC2(g,a,b,n)
    x = unifrnd(a,b,1,n);
    M = max(g(x));
    y = unifrnd(0,M,1,n);
    int = (b-a)*M*mean(y <= g(x));clf;
    hold on;
    axis equal;
    plot(x(y<=g(x)),y(y<=g(x)),'.k','markersize',15);
    fplot(g,[a,b]);
    axis([a,b,-0.1 M+0.1]);
    
end