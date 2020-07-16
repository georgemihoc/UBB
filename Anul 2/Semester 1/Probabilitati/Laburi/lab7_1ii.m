function [m1,m2] = lab7_1ii(x,a)
    n = length(x);
    t = tinv(1 - a/2, n-1);
    s = std(x);
    m1 = mean(x) - t*s/sqrt(n);
    m2 = mean(x) + t*s/sqrt(n);
end