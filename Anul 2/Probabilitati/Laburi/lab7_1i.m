%abaterea standard s
function [m1,m2] = lab7_1i(x,a,s)
    n = length(x);
    z = norminv(1 - a/2,0,1);
    m1 = mean(x) - z*s/sqrt(n);
    m2 = mean(x) + z*s/sqrt(n);
end