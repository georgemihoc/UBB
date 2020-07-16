function y=lab5_1(x,p,n)
    y = zeros(1,n);
    q = cumsum(p);
    for i = 1:n
        u = unifrnd(0,1);
        y(i) = x(find(u<=q,1));
    end
end